#include "hash_tables.h"

/**
 * hash_table_create - Fuction that creates a hash table
 * @size: the size of the array
 *
 * Return: pointer to the newly created hash table
 *		or NULL if error occured
 *
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table_mpya;
	unsigned long int i;

	/* Allocate memory for the hash table structure */
	hash_table_mpya = malloc(sizeof(hash_table_t));
	if (hash_table_mpya == NULL)
		return (NULL);

	/* set the size of the array */
	hash_table_mpya->size = size;
	hash_table_mpya->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_table_mpya->array == NULL)
		return (NULL);

	/* Initialize each element of the array to NULL */

	for (i = 0; i < size; i++)
	{
		hash_table_mpya->array[i] = NULL;
	}

	return (hash_table_mpya);
}
