#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 *main-prints whether numer is positive,negative or zero
 *retun:Always (Success)
 *
 */

/* betty style doc for function main goes there */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
	{
		printf("%d is positive\n", n);
	}
	else if (n < 0)
	{
		printf("%d is negative\n", n);
	}
	else
	{
		printf("%d is zero\n", n);
	}
	/* your code goes there */
	return (0);
}