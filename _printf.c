#include "main.h"

int _putchar(char c);
int print_string(char *str);

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

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
			switch (format[++i])
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
				count += _putchar('%') + _putchar(format[i]);
			}
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
