#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	int middle;

	if (size == 0)
		return (NULL);

	/* Allocate memory for new node */
	root = malloc(sizeof(avl_t));

	if (root == NULL)
		return (NULL);

	/* Find middle element of the array */
	middle = size / 2;

	/* Create root node */
	root->n = array[middle];
	root->left = sorted_array_to_avl(array, middle);
	root->right = sorted_array_to_avl(array + middle + 1, size - middle - 1);
	root->parent = NULL;

	if (root->left != NULL)
		root->left->parent = root;
	if (root->right != NULL)
		root->right->parent = root;

	return (root);
}
