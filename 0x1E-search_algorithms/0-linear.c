#include "search_algos.h"

/**
 * linear_search - performs linear search in an array
 * @array: points to the first element of the array to seact in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: the first index
 *        where the val is loacated or -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	/*check if the array is NULL */
	if (array == NULL)
	{
		return (-1);
	}

	/* iterating through the array */
	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%i]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}
	return (-1);
}
