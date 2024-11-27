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
			i++;
			if (!format[i])
			{
				va_end(args);
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
