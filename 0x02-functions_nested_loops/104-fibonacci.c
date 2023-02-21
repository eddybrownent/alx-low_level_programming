#include <stdio.h>
#define LARGEST 10000000000
/**
* main - main block
* Description: Find and print the first 98 fib numbers starting with 1 and 2.
* Numbers should be coma and space separated.
* Return: 0
*/
int main(void)
{
unsigned long int f1 = 0, bk1 = 1, f2 = 0, bk2 = 2;
unsigned long int hold1, hold2, hold3;
int count;

printf("%lu, %lu, ", bk1, bk2);
for (count = 2; count < 98; count++)
{
if (bk1 + bk2 > LARGEST || f2 > 0 || f1 > 0)
{
hold1 = (bk1 + bk2) / LARGEST;
hold2 = (bk1 + bk2) % LARGEST;
hold3 = f1 + f2 + hold1;
f1 = f2, f2 = hold3;
bk1 = bk2, bk2 = hold2;
printf("%lu%010lu", f2, bk2);
}
else
{
hold2 = bk1 + bk2;
bk1 = bk2, bk2 = hold2;
printf("%lu", bk2);
}
if (count != 97)
printf(", ");
}
printf("\n");
return (0);
}
