#include "binary_trees.h"
/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: the tree
 * @value: the value to search
 *
 * Return: pointer to the node containing a value
 * equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
		return ((binary_tree_t *) tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
