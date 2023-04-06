#include "main.h"

/**
* set_bit - sets the value of a bit to 1 at given index.
* @index: the index.
* @n: the number to set
* Return: 1 if it worked or -1 if error.
*/

int set_bit(unsigned long int *n, unsigned int index)
{
unsigned long int bit = 1UL << index;
if (index >= sizeof(unsigned long int) * 8)
{
return (-1);
}
*n |= bit;
return (1);
}
