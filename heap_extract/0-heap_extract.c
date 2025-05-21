#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - Measures the height of a binary tree
 * Return: Height or 0 if tree is NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
    size_t l, r;

    if (!tree)
        return (0);

    l = tree_height(tree->left);
    r = tree_height(tree->right);
    return (1 + (l > r ? l : r));
}

/**
 * tree_size - Measures the size (number of nodes) in a binary tree
 */
size_t tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_last_node - Retrieves the last node in level-order traversal
 */
heap_t *get_last_node(heap_t *root, size_t idx, size_t size)
{
    heap_t *left, *right;

    if (!root)
        return (NULL);
    if (idx == size)
        return (root);

    left = get_last_node(root->left, 2 * idx + 1, size);
    if (left)
        return (left);

    right = get_last_node(root->right, 2 * idx + 2, size);
    return (right);
}

/**
 * heapify_down - Restores max-heap property starting from a given node
 */
void heapify_down(heap_t *root)
{
    heap_t *largest;
    int tmp;

    while (root)
    {
        largest = root;

        if (root->left && root->left->n > largest->n)
            largest = root->left;
        if (root->right && root->right->n > largest->n)
            largest = root->right;

        if (largest == root)
            break;

        tmp = root->n;
        root->n = largest->n;
        largest->n = tmp;
        root = largest;
    }
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap
 */
int heap_extract(heap_t **root)
{
    heap_t *last, *parent;
    int value;
    size_t size;

    if (!root || !*root)
        return (0);

    value = (*root)->n;

    if (!(*root)->left && !(*root)->right)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    size = tree_size(*root);
    last = get_last_node(*root, 0, size - 1);

    if (last == NULL)
        return (0);

    // Replace root value with last node value
    (*root)->n = last->n;

    parent = last->parent;
    if (parent->right == last)
        parent->right = NULL;
    else
        parent->left = NULL;

    free(last);
    heapify_down(*root);

    return (value);
}
