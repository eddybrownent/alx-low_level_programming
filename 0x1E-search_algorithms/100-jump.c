#include "search_algos.h"

/**
 * jump_search - look for a value in a sorted array usng jump search
 * @array: points to the first element of the array to search
 * @size: number of elements in array
 * @value: value of to search for
 *
 * Return: the firsst index where thr value is found
 *		or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump_step, prev, i;

	if (array == NULL || size == 0)
	{
		return (-1);
	}

	/* calculating the jump step with sqrt of array size */
	jump_step = sqrt(size);
	prev = 0;

	while (array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);

		if (prev + jump_step >= size)
		{
			break;
		}
		prev += jump_step;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev - jump_step,
			prev);

	for (i = prev - jump_step; i <= prev && i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}
	return (-1);
}
