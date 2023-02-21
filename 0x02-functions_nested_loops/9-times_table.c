#include "main.h"
/**
* times_table - print the 9 multiplication table
*
*/
void times_table(void)
{
int num, multip, product;

for (num = 0; num <= 9; num++)
{
_putchar('0');
for (multip = 1; multip <= 9; multip++)
{
_putchar(',');
_putchar(' ');

product = num * multip;

if (product <= 9)
_putchar(' ');
else
_putchar((product / 10) + '0');
_putchar((product % 10) + '0');
}
_putchar('\n');
}
}
