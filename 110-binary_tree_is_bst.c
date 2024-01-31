#include "binary_trees.h"

/**
 * is_BST - Compare node is order to check if a given node
 * is min or max a value
 * @tree: the tree
 * @min: the min value
 * @max: the max value
 *
 * Return: 1 on success or 0 otherwise
 */
int is_BST(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (is_BST(tree->left, min, tree->n - 1) &&
		is_BST(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst -  checks if a binary tree is a valid Binary Search Tree
 * @tree: the tree
 *
 * Return: 1 if success or 0 ortherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_BST(tree, INT_MIN, INT_MAX));
}
