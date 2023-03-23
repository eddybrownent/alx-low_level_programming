#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
* print_numbers - print the numbers
* @separator: the string between the integers
* @n: the number of integers to be printed
* @...:
* Return: 0 if n == 0 else sum
*/
void print_numbers(const char *separator, const unsigned int n, ...)
{
va_list numbers;
unsigned int i;
va_start(numbers, n);
for (i = 0; i < n; i++)
{
printf("%i", va_arg(numbers, int));
if (i != (n - 1) && separator != NULL)
printf("%s", separator);
}
printf("\n");
va_end(numbers);
}
