#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if a single linked list has a cycle
 * @list: pointer to head of list
 * Return: 0 if no cycle, 1 if cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *single, *cycle = list;

    if (!list)
        return (0);

    single = list->next;

    while (single)
    {
        if (single->next)
            single = single->next->next;
        else
            single = single->next;

        cycle = cycle->next;
        if (single == cycle)
            return (1);
    }
    return (0);
}
