#include <stdio.h>
#include "sort.h"

/**
 * sift_down - Fix the heap after removing the root element
 * @array: Array to sort
 * @size: Size of the array
 * @root: Index of the root element
 * @max: Maximum index of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t max)
{
    size_t left_child, right_child, swap, temp;

    while ((left_child = 2 * root + 1) <= max)
    {
        right_child = left_child + 1;
        swap = root;

        if (array[swap] < array[left_child])
            swap = left_child;
        if (right_child <= max && array[swap] < array[right_child])
            swap = right_child;
        if (swap != root)
        {
            temp = array[root];
            array[root] = array[swap];
            array[swap] = temp;
            print_array(array, size);
            root = swap;
        }
        else
            break;
    }
}

/**
 * heapify - Build the heap
 * @array: Array to sort
 * @size: Size of the array
 */
void heapify(int *array, size_t size)
{
    size_t parent;

    for (parent = (size - 2) / 2; (int)parent >= 0; parent--)
        sift_down(array, size, parent, size - 1);
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t end;
    int temp;

    if (array == NULL || size < 2)
        return;

    heapify(array, size);

    for (end = size - 1; end > 0; end--)
    {
        temp = array[0];
        array[0] = array[end];
        array[end] = temp;
        print_array(array, size);
        sift_down(array, size, 0, end - 1);
    }
}
