#include "binary_trees.h"
#include <limits.h>

/**
 * height - Compute the height of a binary tree
 * @tree: Pointer to the root node
 * Return: Height or -1 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	if (!tree)
		return (-1);
	int left_h = height(tree->left);
	int right_h = height(tree->right);
	return (1 + (left_h > right_h ? left_h : right_h));
}

/**
 * is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to root
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 * Return: 1 if valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * is_avl_helper - Recursively checks if a binary tree is a valid AVL
 * @tree: Pointer to the root
 * Return: 1 if valid AVL, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree)
{
	int balance;

	if (!tree)
		return (1);

	int left_height = height(tree->left);
	int right_height = height(tree->right);
	balance = left_height - right_height;
	if (balance < -1 || balance > 1)
		return (0);

	/* Check if subtrees are valid AVL too */
	return (is_avl_helper(tree->left) &&
		is_avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL
 * @tree: Pointer to root node
 * Return: 1 if valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);
	return (is_avl_helper(tree));
}
