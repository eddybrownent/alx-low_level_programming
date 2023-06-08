#include "hash_tables.h"

/**
 * key_index - function to get the index of a key
 *		in a hash table array
 * @key: The key to calculate the index for
 * @size: The size of the array of the hash table
 *
 * Return: the index at which the key is stored
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

	/* calculate the hash value using djb2 hash function */
	hash_value = hash_djb2(key);

/*calculate the index by taking the modulo of the hash value with the size*/
	return (hash_value % size);
}
