# include "main.h"

/**
* print_binary - prints a number in binary
* @n: number to print
* Return: nothing
*/

void print_binary(unsigned long int n)
{
unsigned long int bit = 1UL << (sizeof(unsigned long int) * 8 - 1);
int flag = 0;

while (bit > 0)
{
if (bit & n)
{
_putchar('1');
flag = 1;
}
else if (flag)
{
_putchar('0');
}
bit = bit >> 1;
}
if (!flag)
{
_putchar('0');
}
}
