#include "binary_trees.h"

/**
 * subtree - checks if a subtree contains only value less
 * than n
 * @tree: the root of the tree
 * @n: the value to check
 * @flag: the flag, 1 if left or 0 if right
 *
 * Return: 1 if true or 0 otherwise
 */
int subtree(binary_tree_t *tree, int n, int flag)
{
	int left_sub = 1, right_sub = 1;

	if (tree->left)
		left_sub = subtree(tree->left, n, flag);
	if (tree->right)
		right_sub = subtree(tree->right, n, flag);

	if (flag && tree->n >= n)
		return (0);
	else if (!flag && tree->n <= n)
		return (0);
	return (left_sub * right_sub);
}

/**
 * binary_tree_is_bst - checks if a tree i s correct BST
 * @tree: the tree
 *
 * Return: 1 if true or 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left_sub = 1, right_sub = 1;

	if (tree == NULL)
		return (0);
	if (tree->left)
	{
		if (!subtree(tree->left, tree->n, 1))
			return (0);
		left_sub = binary_tree_is_bst(tree->left);
	}
	else
		return (1);
	if (tree->right)
	{
		if (!subtree(tree->left, tree->n, 1))
			return (0);
		right_sub = binary_tree_is_bst(tree->right);
	}
	else
		return (1);
	return (left_sub * right_sub);
}

/**
 * tree_height_recursion - measures the height of a tree
 * @tree: the tree
 *
 * Return: height
 */
size_t tree_height_recursion(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree->left)
		left_h = tree_height_recursion(tree->left);
	if (tree->right)
		right_h = tree_height_recursion(tree->right);
	return ((left_h > right_h) ? left_h + 1 : right_h + 1);
}

/**
 * binary_tree_balance - checks the balance of a tree
 * @tree: the tree
 *
 * Return: balance
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_b = 0, right_b = 0;

	if (tree)
	{
		if (tree->left)
			left_b = tree_height_recursion(tree->left);
		if (tree->right)
			right_b = tree_height_recursion(tree->right);
		return (left_b - right_b);
	}
	else
		return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: the tree
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_sub = 1, right_sub = 1;

	if (tree == NULL)
		return (0);
	if ((binary_tree_balance(tree) != 1 && binary_tree_balance(tree) != 0 &&
	binary_tree_balance(tree) != -1) || !binary_tree_is_bst(tree))
		return (0);
	if (tree->left)
		left_sub = binary_tree_is_avl(tree->left);
	if (tree->right)
		right_sub = binary_tree_is_avl(tree->right);
	return (left_sub * right_sub);
}
