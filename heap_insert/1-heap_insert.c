#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify - Maintains the Max Heap property after insertion
 * @node: The newly inserted node
 */
void heapify(heap_t *node)
{
while (node->parent && node->n > node->parent->n)
{
int temp = node->n;
node->n = node->parent->n;
node->parent->n = temp;
node = node->parent;
}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *new_node = binary_tree_node(NULL, value);
if (new_node == NULL)
return (NULL);
if (*root == NULL)
{
*root = new_node;
return (new_node);
}

/* Find the parent for the new node */
{
heap_t *parent = *root;
while (parent->left && parent->right)
{
if (binary_tree_size(parent->left) > binary_tree_size(parent->right))
parent = parent->right;
else
parent = parent->left;
}
/* Insert the new node */
if (parent->left == NULL)
parent->left = new_node;
else
parent->right = new_node;

new_node->parent = parent;
}
/* Restore the Max Heap property */
heapify(new_node);

return (new_node);
}
