#include "main.h"
/**
* more_numbers - print the numbers
* Return: 10 times of the numbers 0 to 14
*/

void more_numbers(void)
{
int i, x;

for (i = 0; i < 10; i++)
{
for (x = 0; x <= 14; x++)
{
if (x >= 10)
_putchar((x / 10) + '0');
_putchar((x % 10) + '0');
}
_putchar('\n');
}
}
