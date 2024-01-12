#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node = (listint_t *)malloc(sizeof(listint_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = number;

    if ( *head == NULL || number <= (*head)->n )
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        listint_t *current = *head;

        while (current->next != NULL && current->next->n < number)
        {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    return (*head);
}
