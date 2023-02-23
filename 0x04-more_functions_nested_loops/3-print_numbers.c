#include "main.h"
/**
* print_numbers - print numbers
* Return: the numbers 0 uto 9
*/

void print_numbers(void)
{
int x;
for (x = 0; x <= 9; x++)
{
_putchar(x + '0');
}
_putchar('\n');
}
