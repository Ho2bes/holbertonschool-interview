#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Crée un nœud d'arbre binaire
 * @parent: Pointeur vers le nœud parent du nœud à créer
 * @value: Valeur à placer dans le nouveau nœud
 *
 * Return: Pointeur vers le nouveau nœud, ou NULL en cas d'échec
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
	return (NULL);

	/* Set the value of the new node and its parent */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
