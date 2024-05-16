#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "search_algos.h"


/**
 * @brief Performs an advanced binary search on a sorted array.
 *
 * This function implements an advanced binary search algorithm that prints the
 * portion of the array being searched at each step. It returns the index of the
 * first occurrence of the target value if found, or -1 if not found.
 *
 * @param array The sorted array to search in.
 * @param size The size of the array.
 * @param value The target value to search for.
 *
 * @return The index of the first occurrence of the target value in the array,
 *         or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
    size_t i, mid;
    int result;

    if (array == NULL)
        return (-1);

    printf("Searching in array:");
    for (i = 0; i < size; ++i)
    {
        printf(" %d", array[i]);
        if (i < size - 1)
            printf(",");
    }
    printf("\n");

    if (size == 1 && array[0] != value)
        return (-1);

    mid = size / 2;

    if (array[mid] == value)
    {
        if (size % 2 == 0)
            return (mid - 1);
        return (mid);
    }
    else if (array[mid] > value)
    {
        result = advanced_binary(array, mid, value);
    }
    else
    {
        result = advanced_binary(array + mid + 1, size - mid - 1, value);
        if (result != -1)
            result += mid + 1;
    }
    return (result);
}