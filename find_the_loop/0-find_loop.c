#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

listint_t *find_listint_loop(listint_t *head) {
    listint_t *fast = head, *slow = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow;
        }
    }

    return NULL;
}