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

    if (n < 0)  // Handle negative numbers
    {
        count += _putchar('-');
        num = -n;
    }
    else
    {
        num = n;
    }

    // Print digits using recursion
    if (num / 10)
        count += print_number(num / 10);

    count += _putchar((num % 10) + '0');  // Print the last digit

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
