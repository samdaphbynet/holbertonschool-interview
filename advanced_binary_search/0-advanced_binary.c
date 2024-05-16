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
	size_t i = 0;
    int middle = ((size - 1) / 2);
	int result = 0;

	if (array == NULL || size < 1)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++){
        printf("%d", array[i]);
        if (i != (size - 1))
            printf(", ");
        else 
            printf("\n");
    }

	if (array[middle] == value && middle == 0) {
        return (middle);
    }else if (size == 1) {
        return (-1);
    }

	if (array[middle] >= value)
        return (advanced_binary(array, middle + 1, value));
    
    middle++;
    result = advanced_binary(&array[middle], size - middle, value);

	if (result == -1)
        return (-1);
    return (result + middle);
}