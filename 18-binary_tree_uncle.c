#include "binary_trees.h"

/**
 * search_uncle - search uncle
 * @node: the node
 *
 * Return: uncle
 */

binary_tree_t *search_uncle(binary_tree_t *node)
{
	binary_tree_t *gr_parent = NULL;

	if (!node || !(node->parent))
		return (NULL);
	gr_parent = node->parent;

	/* checks for uncle left and right */
	if (gr_parent->left && (gr_parent->left != node))
		return (gr_parent->left);
	else if (gr_parent->right && (gr_parent->right != node))
		return (gr_parent->right);
	return (NULL);
}

/**
 * binary_tree_uncle - finds the uncle of a node
 * @tree: the tree
 *
 * Return: uncle
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !(node->parent))
		return (NULL);
	return (search_uncle(node->parent));
}
