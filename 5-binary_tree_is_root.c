#include "binary_trees.h"
/**
 * binary_tree_is_root - Checks if a gven node is root
 * @node: the node
 *
 * Return: 1 if node is root or 0 otherwise
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	int root = 0;

	if (node && !(node->parent))
		root = 1;

	return (root);
}
