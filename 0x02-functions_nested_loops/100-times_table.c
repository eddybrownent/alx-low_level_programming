#include "main.h"

/**
* print_times_table - prints the times table of the input
* starting with 0
* @n: the value of the times to be printed
*/
void print_times_table(int n)
{
int numb, multip, product;
if (n >= 0 && n <= 15)
{
for (numb = 0; numb <= n; numb++)
{
_putchar('0');
for (multip = 1; multip <= n; multip++)
{
_putchar(',');
_putchar(' ');
product = numb * multip;
if (product <= 99)
_putchar(' ');
if (product <= 9)
_putchar(' ');
if (product >= 100)
{
_putchar((product / 100) + '0');
_putchar((product / 10) % 10 + '0');
}
else if (product <= 99 && product >= 10)
{
_putchar((product / 10) + '0');
}
_putchar((product % 10) + '0');
}
_putchar('\n');
}
}
}
