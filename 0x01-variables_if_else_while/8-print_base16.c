#include <stdio.h>

/**
 * main - Entry point
 *
 * Description -  prints all the numbers of base 16 in lowercase,
 * followed by a new line
 *
 * Return: Always 0 (Succes)
 */

int main(void)
{
	int n;

	for (n = 0 ; n < 16 ; n++)
	{
		if (n < 10)
		{
			putchar('0' + n);
		}
		else
		{
			putchar(87 + n);
		}
	}
	putchar('\n');
	return (0);
}
