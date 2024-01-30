#include "binary_trees.h"

/**
 * binary_tree_height_balance - measures the height balance of a binary tree
 * @tree: the tree
 *
 * Return: balance
 */
size_t binary_tree_height_balance(const binary_tree_t *tree)
{
        size_t left_h = 0, right_h = 0;

        if (tree == NULL)
                return (0);
        if (tree->left)
                left_h = 1 + binary_tree_height_balance(tree->left);
        if (tree->right)
                right_h = 1 + binary_tree_height_balance(tree->right);

        if (left_h > right_h)
                return (left_h);
        return (right_h);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: the tree
 *
 * Return: balance
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		left_h += 1 + binary_tree_height_balance(tree->left);
	if (tree->right)
		right_h += 1 + binary_tree_height_balance(tree->right);

	return (left_h - right_h);
}

