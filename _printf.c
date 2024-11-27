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
/** print_int prints an integer to stdout.
* @n: the integer to print.
* Return: Character count printed.
*/
int print_int(int n)
{
int count = 0;
char str[12];
/* Handle the casse for 0 directly*/
if (n == 0)
{
count += _putchar('0');
return (count);
}
/* Convert the integer to a string (handle negative numbers)*/
int i = 0;
if (n < 0)
{
str[i++] = '-';
n = -n; /* Make number positive for easier processing*/
}
/* Store each digit of the integer in reverse order*/
int temp = n;
while (temp > 0)
{
str[i++] = (temp % 10) + '0'; // Convert the digit to a char
temp /= 10;
}
/* Print the string in correct order (reverse the string)*/
for (int j = (n < 0) ? 1 : 0; i > j; i--)
{
count += _putchar(str[i - 1]);
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
		count += print_int(va_arg(args, int));
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
			if (!format[i + 1])
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
