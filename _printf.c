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
int print_numbers(int n)
{
    int count = 0;
    int temp = n;
    int divisor = 1;

    if (n < 0)
    {
        count += _putchar('-');
        n = -n;
    }

    /* Find the highest power of 10 less than or equal to n */
    while (temp / divisor >= 10)
        divisor *= 10;

    /* Print each digit of the number */
    while (divisor > 0)
    {
        count += _putchar((n / divisor) + '0');
        n %= divisor;
        divisor /= 10;
    }

    return (count);
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
