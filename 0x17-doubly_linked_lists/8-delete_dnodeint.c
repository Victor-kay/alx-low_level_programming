#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a
 * dlistint_t linked list
 *
 * @head: head of the list
 * @index: index of the node to be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i = 0;

	while (current != NULL)
	{
		if (i == index)
		{
			if (current->prev)
				current->prev->next = current->next;
			else
				*head = current->next;

			if (current->next)
				current->next->prev = current->prev;

			free(current);
			return (1);
		}
		current = current->next;
		i++;
	}

	return (-1);
}
