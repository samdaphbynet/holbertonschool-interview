#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int is_palindrome(listint_t **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return 1;
    }

    listint_t *slow = *head;
    listint_t *fast = *head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    listint_t *prev = NULL;
    listint_t *current = slow->next;

    while (current != NULL)
    {
        listint_t *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    slow->next = prev;
    listint_t *p1 = *head;
    listint_t *p2 = slow->next;

    while (p2 != NULL)
    {
        if (p1->n != p2->n)
        {
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    current = slow->next;
    prev = NULL;

    while (current != NULL)
    {
        listint_t *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    slow->next = prev;

    return 1;
}
