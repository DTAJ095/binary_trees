#include "binary_trees.h"

/**
 * compare_depth - compare the depth
 * @tree: the tree
 *
 * Return: depth
 */

int compare_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (compare_depth(tree->left) + 1 + compare_depth(tree->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: the tree
 *
 * Return: 1 if true or 0 if not
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);
	if (tree && (!tree->left && !tree->right))
		return (1);

	left_h = compare_depth(tree->left);
	right_h = compare_depth(tree->right);

	if (left_h - right_h == 0)
		return (1);

	return (0);
}
