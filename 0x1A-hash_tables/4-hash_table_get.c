#include "hash_tables.h"

/**
 * hash_table_get - gets the value associated with a key in a hash table
 * @ht: the hash table
 * @key: the key to search for
 *
 * Return: the value associated with the key else
 *		NULL if key not found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);

		node = node->next;
	}

	return (NULL);
}
