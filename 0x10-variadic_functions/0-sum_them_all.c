#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
* sum_them_all - prints the sum of intergers
* @n: integer
* Return: 0 if n == 0
* else sum
*/
int sum_them_all(const unsigned int n, ...)
{
unsigned int i, sum = 0;
va_list numbers;
va_start(numbers, n);
for (i = 0; i < n; i++)
sum += va_arg(numbers, int);
va_end(numbers);
return (sum);
}
