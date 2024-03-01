#include "palindrome.h"

/**
 * is_palindrome - function that checks a given integer is a palindrome
 * @n: number of to check if it is a palindrome
 * @Return: 1 if it is a palindrome and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
    unsigned long reversed = 0, origin = 1;

    while (n != 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    if (reversed == origin)
        return (1);
    else
        return (0);
}