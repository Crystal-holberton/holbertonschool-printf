#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *str);
int handle_form(char format, va_list args);
int print_number(int n);

#endif
