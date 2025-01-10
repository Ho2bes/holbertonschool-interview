#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: Double pointer to the head of the list.
 * @number: The number to insert.
 *
 * Return: Address of the new node, or NULL if it failed.
 */

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node, *current, *prev;

    if (!head)
        return (NULL);

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(listint_t));
    if (!new_node)
        return (NULL);
    new_node->n = number;
    new_node->next = NULL;


    if (!(*head) || (*head)->n >= number)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }


    current = *head;
    while (current && current->n < number)
    {
        prev = current;
        current = current->next;
    }


    new_node->next = current;
    prev->next = new_node;

    return (new_node);
}
