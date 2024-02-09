#include "lists.h"

/**
 *  is_palindrome - that checks if a linked list is palindrome
 *  @head: linked list head
 *  Return: 1 if is palindrome or 0 if not
 */

int is_palindrome(listint_t **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return 1; // An empty list or a list with only one node is considered a palindrome
    }

    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *prev;
    listint_t *current;
    listint_t *p1;
    listint_t *p2;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    prev = NULL;
    current = slow->next;
    while (current != NULL) {
        listint_t *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    slow->next = prev;

    p1 = *head;
    p2 = slow->next;
    while (p2 != NULL) {
        if (p1->n != p2->n) {
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    current = slow->next;
    prev = NULL;
    while (current != NULL) {
        listint_t *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    slow->next = prev;

    return 1;
}