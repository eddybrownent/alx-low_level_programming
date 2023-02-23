#include "main.h"

/**
* print_diagonal - draws a diagonal line
* @n: number of times \ should be printed
*/
void print_diagonal(int n)
{
if (n <= 0)
{
_putchar('\n');
}
else
{
int i, d;

for (i = 0; i < n; i++)
{
for (d = 0; d < n; d++)
{
if (d == i)
_putchar('\\');
else if (d < i)

_putchar(' ');
}
_putchar('\n');
}
}
}
