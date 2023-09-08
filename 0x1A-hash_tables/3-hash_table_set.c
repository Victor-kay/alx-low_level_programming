#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table to add or update the key/value pair.
 * @key: The key to add or update (cannot be an empty string).
 * @value: The value associated with the key (can be an empty string).
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *new_node = NULL;
    hash_node_t *existing_node = NULL;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    index = key_index((const unsigned char *)key, ht->size);

    /* Check for existing node with the same key */
    existing_node = ht->array[index];
    while (existing_node != NULL)
    {
        if (strcmp(existing_node->key, key) == 0)
        {
            /* Update the value if key already exists */
            free(existing_node->value);
            existing_node->value = strdup(value);
            if (existing_node->value == NULL)
                return (0);
            return (1);
        }
        existing_node = existing_node->next;
    }

    /* Allocate memory for a new node and set key/value */
    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    /* Insert the new node at the beginning of the list */
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}
