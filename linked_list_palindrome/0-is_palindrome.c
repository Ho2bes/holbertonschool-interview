#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * reverse_list - Reverses a linked list
 * @head: Pointer to the head of the list
 *
 * Return: Pointer to the new head
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL;

    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Pointer to the head of the list
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *rev, *temp;

    if (!head || !*head || !(*head)->next)
        return (1);

    /* Find the middle of the list */
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse second half */
    rev = reverse_list(slow);
    temp = rev;

    /* Compare first and second halves */
    while (rev)
    {
        if ((*head)->n != rev->n)
        {
            reverse_list(temp);
            return (0);
        }
        *head = (*head)->next;
        rev = rev->next;
    }

    /* Restore the list (optional) */
    reverse_list(temp);

    return (1);
}
