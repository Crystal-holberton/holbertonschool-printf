#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: is a character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i, count = 0;

	va_list args;

	va_start(args, format);

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
		}
		else
		{
		}
		i++;
	}
	va_end(args);
	return (count);
}
