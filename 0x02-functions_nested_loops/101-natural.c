#include <stdio.h>

/**
* main - prints the sum of all multiples of 3 and 5 upto 1024
* Return: 0 Always (Success)
*/
int main(void)
{
int x, z = 0;

while (x < 1024)
{
if ((x % 3 == 0) || (x % 5 == 0))
{
z += x;
}
x++;
}
printf("%d\n", z);
return (0);
}
