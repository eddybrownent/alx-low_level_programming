#include <stdio.h>
/**
* main - Entry point
*
* Description: all possible different combinations of two digits.
*
* Return: Always 0 (Success)
*
*/

int main(void)
{
int x, y;
for (x = 0; x < 9; x++)
for (y = x + 1; y < 10; y++)
{
putchar(x + '0');
putchar(y + '0');
putchar(',');
}
putchar('\n');
return (0);
}
