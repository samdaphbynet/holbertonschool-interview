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
int advanced_binary(int *array, size_t size, int value) {
    int middle = size / 2;
    int left = 0;
    int right = size - 1;
    int i;
    
    while (left <= right) {
        printf("Searching in array: ");
        for (i = left; i <= right; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
        
        if (array[middle] == value) {
            return middle;
        } else if (array[middle] > value) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
        
        middle = (left + right) / 2;
    
    }

    return -1;
}