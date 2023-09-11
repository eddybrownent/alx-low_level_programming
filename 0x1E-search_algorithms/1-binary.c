#include "search_algos.h"

/**
 * binary_search - performs binary search in a sorted array
 * @array: points to the first element of the the array
 * @size: numeber of elements in the array
 * @value: value to search for
 *
 * Return: The index where the value is located or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	int left, right, mid, i;

	if (array == NULL)
	{
		return (-1);
	}

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		/* Calculate the middle index */
		mid = (right + left) / 2;

		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			printf("%i", array[i]);
			if (i < right)
			{
				printf(", ");
			}
		}
	printf("\n");
	if (array[mid] == value)
		return (mid);
	else if (array[mid] < value)
		left = mid + 1;
	else
		right = mid - 1;
	}
return (-1);
}
