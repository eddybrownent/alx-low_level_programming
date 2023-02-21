#include <stdio.h>

/**
* main - prints the sum of even fibonacci numbers
* less than 4,000,000
* Return: 0
*/
int main(void)
{
int a = 0;
long b = 1, c = 2, sum = c;

while (c + b < 40000000)
{
c += b;
if (c % 2 == 0)
sum += c;
b = c - b;
++a;
printf("%ld\n", sum);
return (0);
}
}
