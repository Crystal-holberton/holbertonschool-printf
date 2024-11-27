#include "main.h"

/**
 * print_string - prints a string to stdout
 * @str: string to print
 * Return: Character count printed
 */
int print_string(char *str)
{
	int count = 0;

	if (!str)
	{
		str = "(null)";
	}
	while (*str)
	{
		count += _putchar(*str++);
	}
	return (count);
}
/**
 * print_int - prints an integer to stdout
 * @n: integer to print
 * Return: the number of characters printed
 */
int print_number(int n)
{
    int count = 0;
    unsigned int num;

    // Handle negative numbers
    if (n < 0)
    {
        count += _putchar('-');
        num = -n;  // Make n positive for easier digit handling
    }
    else
    {
        num = n;
    }

    // Handle the special case when n is 0
    if (num == 0)
    {
        count += _putchar('0');
        return count;
    }

    // Array to store the digits
    int digits[10];
    int digit_count = 0;

    // Extract digits from the number
    while (num > 0)
    {
        digits[digit_count++] = num % 10;  // Store the last digit
        num /= 10;  // Reduce the number
    }

    // Print the digits in reverse order (most significant digit first)
    for (int i = digit_count - 1; i >= 0; i--)
    {
        count += _putchar(digits[i] + '0');  // Convert digit to char and print
    }

    return count;
}
/**
 * handle_form - handles format specifiers
 * @format: specifier
 * @args: arguments
 * Return: Character count printed
 */
int handle_form(char format, va_list args)
{
	int count = 0;

	switch (format)
	{
	case 'c':
		count += _putchar(va_arg(args, int));
		break;
	case 's':
		count += print_string(va_arg(args, char *));
		break;
        case 'd':
        case 'i':
                count += print_number(va_arg(args, int));
        break;
	case '%':
		count += _putchar('%');
		break;
	default:
		count += _putchar('%');
		count += _putchar(format);
		break;
	}
	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: is a character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
	{
		return (-1);
	}

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				return (-1);
			}
			count += handle_form(format[++i], args);
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
