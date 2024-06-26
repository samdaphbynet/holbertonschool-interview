#include "binary_trees.h"

/**
 * createNode - Function that creates a new node
 *
 * @data: the new AVL tree node
 * Return: new node
 */
avl_t *createNode(int data)
{
    avl_t *newNode = (avl_t *)malloc(sizeof(avl_t));
    if (newNode)
    {
        newNode->n = data;
        newNode->left = newNode->right = NULL;
        newNode->parent = NULL;
    }
    return newNode;
}

/**
 * sorted_array_to_avl_helper - Function to build AVL tree from sorted array
 *
 * @array: array to build
 * @start: start index
 * @end: end index
 *
 * Return: array containing the sorted array
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end)
{
    int mid;
    avl_t *root;

    if (start > end)
        return NULL;

    mid = start + (end - start) / 2;

    root = createNode(array[mid]);
    if (root == NULL)
        return NULL;

    root->left = sorted_array_to_avl_helper(array, start, mid - 1);
    if (root->left != NULL)
        root->left->parent = root;
    root->right = sorted_array_to_avl_helper(array, mid + 1, end);
    if (root->right != NULL)
        root->right->parent = root;

    return root;
}

/**
 * sorted_array_to_avl - Main function to build AVL tree from sorted array
 *
 * @array: array to build
 * @size: number of elements in array
 *
 * Return: array containing the sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return NULL;

    return sorted_array_to_avl_helper(array, 0, size - 1);
}