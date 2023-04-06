#include "main.h"


/**
* flip_bits - count the number of bits
* you would neeed  to flip to get to
* foem one number to another.
* @n: the first number.
* @m: the second number.
* Return: number of bits needed to flip
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int dif = n ^ m;
unsigned int count  = 0;

while (dif)
{
count = count + (dif & 1);
dif = dif >> 1;
}
return (count);
}
