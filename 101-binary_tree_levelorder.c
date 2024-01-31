#include "binary_trees.h"

/**
 * binary_tree_height_aux - measures the height
 * @tree: the tree
 *
 * Return: height
 */
size_t binary_tree_height_aux(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		left_h = 1 + binary_tree_height_aux(tree->left);
	if (tree->right)
		right_h = 1 + binary_tree_height_aux(tree->right);

	if (left_h > right_h)
		return (left_h);
	return (right_h);
}

/**
 * print_level_order - print each level
 * @tree: the tree
 * @level: the level
 * @func: pointer to the func to call each node
 *
 * Return: void
 */
void print_level_order(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level_order(tree->left, level - 1, func);
		print_level_order(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: the tree
 * @func: pointer to the func to call each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0, len = 1;

	if (!tree || !func)
		return;
	height = binary_tree_height_aux(tree) + 1;

	while (len <= height)
	{
		print_level_order(tree, len, func);
		len++;
	}
}
