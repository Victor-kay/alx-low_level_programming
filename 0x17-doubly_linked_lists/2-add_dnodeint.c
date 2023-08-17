#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning
 * of a dlistint_t list
 *
 * @head: pointer to the head of the list
 * @n: value of the element
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    dlistint_t *new_node, *temp;

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->prev = NULL;

    temp = *head;
    *head = new_node;

    if (temp != NULL)
    {
        new_node->next = temp;
        temp->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    return (new_node);
}
