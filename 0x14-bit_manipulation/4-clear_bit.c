#include "main.h"

/**
* clear_bit - sets the value of a bit to 0 at given index.
* @index: the index
* @n: the number to be set
* Return: 1 if it works or -1 if error
*/

int clear_bit(unsigned long int *n, unsigned int index)
{
unsigned long bit = 1UL << index;

if (index >= sizeof(unsigned long int) * 8)
{
return (-1);
}

bit = ~bit;
*n = *n & bit;
return (1);
}
