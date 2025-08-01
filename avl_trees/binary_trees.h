#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

/* Prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
/* ... (autres prototypes nécessaires) ... */

#endif
