#include "binary_trees.h"

/**
 * nodes_counter - counts nodes
 * @root: the root
 *
 * Return: number of nodes
 */
int nodes_counter(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + nodes_counter(root->left) + nodes_counter(root->right));
}

/**
 * complete_tree - checks if the tree is complete
 * @root: the root
 * @index: the index of node
 * @n: the number of trees nodes
 *
 * Return: 1 if the tree is heap or 0 otherwise
 */
int complete_tree(binary_tree_t *root, int index, int n)
{
	if (!root)
		return (0);
	
	if (index >= n)
		return (0);
	if (!root->left && !root->right)
		return (1);
	if (root->right && !root->left)
		return (0);
	if (root->left && !root->right)
		return (complete_tree(root->left, index * 2 + 1, n));
	return (complete_tree(root->left, index * 2 + 1, n) &&
		complete_tree(root->right, index * 2 + 2, n));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: the tree
 *
 * Return: Void
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nodes;
	binary_tree_t *root;

	if (tree == NULL)
		return (0);
	root = (binary_tree_t *)tree;
	nodes = nodes_counter(root);

	return (complete_tree(root, 0, nodes));
}
