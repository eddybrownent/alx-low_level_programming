#include "hash_tables.h"

/**
 * shash_table_create - create a sorted hash table
 * @size: the size of hash table
 *
 * Return: pointer to the new table otherwise NULL
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *sorted_table;

	/* Allocate memory for the sorted hash table */
	sorted_table = malloc(sizeof(shash_table_t));
	if (sorted_table == NULL)
		return (NULL);
	sorted_table->size = size;
	sorted_table->shead = NULL;
	sorted_table->stail = NULL;
	sorted_table->array = malloc(sizeof(shash_node_t) * size);
	if (sorted_table->array == NULL)
	{
		free(sorted_table);
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		sorted_table->array[i] = NULL;
	}
	return (sorted_table);
}


/**
 * create_shash_node - create a node for the sorted hash table
 * @key: the key for the data
 * @value: data to be stored
 *
 * Return: pointer to the new node otherwise NULL
 */

shash_node_t *create_shash_node(const char *key, const char *value)
{
	shash_node_t *node;

	/* Allocate memory for a hash node */
	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (NULL);

	/* Duplicate the key string */
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}

	/* Duplicate the value string */
	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}
	node->next = node->snext = node->sprev = NULL;

	return (node);
}


/**
 * add_to_sorted_list - add a node to the sorted(using key's ASCII) linked list
 * @table: the sorted hash table
 * @node: the node to add
 *
 * Return: Void
 */

void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *current_node;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}
	current_node = table->shead;
	while (current_node != NULL)
	{
		if (strcmp(node->key, current_node->key) < 0)/*Compare keys' ASCII values*/
		{
			node->snext = current_node;
			node->sprev = current_node->sprev;
			current_node->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		current_node = current_node->snext;
	}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}


/**
 * shash_table_set - sets a key_value pair in the sorted hash table
 * @ht: sorted hash table
 * @key: key of the data
 * @value: the data to be added
 *
 * Return: 1 otherwise NULL
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node, *current_node;
	char *new_value;
	unsigned long int index;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
			key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	current_node = ht->array[index];
	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(current_node->value);
			current_node->value = new_value;
			return (1);
		}
		current_node = current_node->next;
	}
	node = create_shash_node(key, value);
	if (node == NULL)
		return (0);
	node->next = ht->array[index];
	ht->array[index] = node;
	add_to_sorted_list(ht, node);

	return (1);
}


/**
 * shash_table_get - gets a value from the sorted hash table
 * @ht: sorted hash table
 * @key: key of the data
 *
 * Return: the value associated with the key otherwise NULL
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *current_node;
	unsigned long int index;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
			key == NULL || strlen(key) == 0)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	current_node = ht->array[index];
	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
			return (current_node->value);
		current_node = current_node->next;
	}

	return (NULL);
}


/**
 * shash_table_print - to print the sorted hash table
 * @ht: sorted hash table to print
 *
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node;
	char flag = 0;/*0, indicating that no data has printed yet.*/

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	current_node = ht->shead;
	while (current_node != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", current_node->key, current_node->value);
		flag = 1; /* Set flag to 1 after printing the first pair */
		current_node = current_node->snext;
	}
	printf("}\n");
}


/**
 * shash_table_print_rev - print the sorted hash table in reverse
 * @ht: sorted hash table to print
 *
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current_node;
	char flag = 0; /* 0, indicating that no data has been printed yet */

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	current_node = ht->stail;
	while (current_node != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", current_node->key, current_node->value);
		flag = 1;
		current_node = current_node->sprev;
	}
	printf("}\n");
}


/**
 * shash_table_delete - to delete the sorted hash table
 * @ht: sorted hash table to delete
 *
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *next_node;
	unsigned long int i;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (i = 0; i < ht->size; i++)
	{
		while (ht->array[i] != NULL)
		{
			next_node = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = next_node;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
