#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted singly linked list
 *               of integers using linear skip.
 * @list: A pointer to the head of the linked list to search.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where the value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *node, *jump;

    if (list == NULL)
        return (NULL);

    node = jump = list;

    while (jump->next && jump->n < value)
    {
        node = jump;
        printf("Value checked at index [%lu] = [%d]\n", jump->index, jump->n);

        if (jump->express == NULL)
        {
            while (jump->next)
                jump = jump->next;
            break;
        }

        jump = jump->express;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", node->index, jump->index);

    while (node->index <= jump->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
        if (node->n == value)
            return (node);
        node = node->next;
    }

    return (NULL);
}
