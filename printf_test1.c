#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: is a character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int len = 0;
	va_list arg_list;
	va_start(arg_list, format);


