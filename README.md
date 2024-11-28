Project: C - printf
In this project, Crystal, Zib, and Santana are creating our own printf function
In this function we will be producing an output according to the format prototype: int _printf(const char *format, ...);
This should return the number of characters printed.
For the prototype to work the main.h header file is created and implemented in the project.

main.h:
The header file that contains all the required library headers and prototypes to make the function work.

_putchar.c:
The C file that prints the characters without needing to use the write function constantly.

main.c:
The input C file to check that the _printf function works correctly.

man_3_printf:
The custom manual explaining the use and functionality of _printf function.

_printf.c:
The custom printf function code to be used to create output similar but not completely the same as the original printf.

The code:
In the _printf function itself there are actually four seperate functions-

print_string(char *str)
Function for 's' conversion specifier to print a string.
Returns the string '(null)' if str input is NULL.
Counts the number of characters printed and returns the count.

print_number(int n)
Function for 'd' and 'i' conversion specifiers to print integers.
Handles negative numbers by printing '-' and then the positive equivalent.
Recusively breaks the numbers into digits with the division '/' and modulus '%' operators.
Counts and returns the number of characters printed.

handle_form(char format, va_list args)
The function for handling all the listed specifiers.
A switch statment is used to match the format specifiers.
case 'c' prints a single character
case 's' calls print_string to print a string
case 'd'  and 'i' calls print_number to print an integer
case '%' prints a literal %
default prints unrecognised format characters with % before them
This function counts and returns the number of characters printed for the given format specifiers

_printf(const char *format, ...)
The main printing function that implements all the previous functions.
Takes a format string and a variable amount of arguments that are gained via the va_list.
A while loop is used to process each character in the format string.
If a % is encountered it will call handle_form to match the appropriate specifier to process and print print the argument.
_putchar is used to print to standard output of the number of characters printed.
The _printf function accumulates the total number of characters printed by summing the results.
_printf then returns the total number of characters printed.

Error Handling:
As with any type of code there can be errors.
If the string is NULL, _printf will return -1
If a % is at the end of a string without a valid specifier, _printf will return -1
