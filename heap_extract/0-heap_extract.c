#include "binary_trees.h"

/**
 * heap_extract - Extracts the root value from a max binary heap.
 * @root: Double pointer to the root of the heap.
 *
 * Return: The value stored in the root node, or 0 if the function fails.
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *last, *parent = NULL;

	if (!root || !(*root))
		return (0);

	extracted_value = (*root)->n;

	last = get_last_node(*root);
	if (last == *root)
	{
		free(*root);
		*root = NULL;
		return (extracted_value);
	}

	(*root)->n = last->n;

	parent = last->parent;
	if (parent->left == last)
		parent->left = NULL;
	else
		parent->right = NULL;

	free(last);

	sift_down(*root);

	return (extracted_value);
}

/**
 * get_last_node - Finds the last node in the level order of the heap.
 * @root: Pointer to the root of the heap.
 *
 * Return: A pointer to the last node.
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t **queue;
	size_t front = 0, rear = 0, size = 1024;
	heap_t *last = NULL;

	queue = malloc(sizeof(heap_t *) * size);
	if (!queue)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		last = queue[front++];

		if (last->left)
			queue[rear++] = last->left;
		if (last->right)
			queue[rear++] = last->right;
	}

	free(queue);
	return (last);
}

/**
 * sift_down - Rebuilds the heap property by sifting down the node.
 * @node: The node to sift down.
 */
void sift_down(heap_t *node)
{
	heap_t *largest;
	int temp;

	while (node)
	{
		largest = node;
		if (node->left && node->left->n > largest->n)
			largest = node->left;
		if (node->right && node->right->n > largest->n)
			largest = node->right;

		if (largest == node)
			return;

		temp = node->n;
		node->n = largest->n;
		largest->n = temp;

		node = largest;
	}
}
