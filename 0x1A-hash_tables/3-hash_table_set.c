#include "hash_tables.h"

/**
 * hash_table_set - func to add/update an element in the hash table
 * @ht: the hash table to add/upadate the key to
 * @key: the key to add
 * @value: the value associated with the key
 *
 * Return: 1 if success , otherwise 0
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *temp;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	/* Get the index of the key in the hash table */
	index = key_index((const unsigned char *)key, ht->size);

	/*check if the key already exists in the linked list at the index */
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			/* key already exits, update the value */
			free(temp->value);
			temp->value = strdup(value);
			return (1);
		}
		temp = temp->next;
	}

	/* Key does not exist, create a new node and add it at the beginning */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
