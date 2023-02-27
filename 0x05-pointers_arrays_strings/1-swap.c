#include "main.h"
/**
 * swap_int - swaps the values of the two intergers
 * @a: integer to swap
 * @b: interger to swap
 */
void swap_int(int *a, int *b)
{
int x;

x = *a;
*a = *b;
*b = x;
}
