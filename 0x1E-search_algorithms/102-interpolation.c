#include "search_algos.h"

/**
 * interpolation_search - searched for a value in a sorted array
 *				using Interpolation search algorithm
 * @array: points to the first element of the array
 * @size: number of elements in the array
 * @value: The value to search for
 *
 * Return: The first index where the value is located at
 *		or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low, high, pos;

	if (array == NULL || size == 0)
	{
		return (-1);
	}

	low = 0;
	high = size - 1;

	while (low <= high && value >= array[low] && value <= array[high])
	{
		pos = low + ((high - low) / (array[high] - array[low])) *
			(value - array[low]);
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
		{
			return (pos);
		}

		if (array[pos] < value)
		{
			low = pos + 1;
		}
		else
		{
			high = pos - 1;
		}
	}

		printf("Value checked array[%lu] is out of range\n", low);

		return (-1);
}
