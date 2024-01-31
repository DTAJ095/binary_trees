#include "binary_trees.h"

/**
 * min_finder - find the min root
 * @root: the root
 *
 * Return: min root
 */
bst_t *min_finder(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: the root
 * @value: the value to remove
 *
 * Return: ointer to the new root node of the tree after
 * removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *parent;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			tmp = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(tmp);
		}
		else
		{
			tmp = min_finder(root->right);
			root->n = tmp->n;
			root->right = bst_remove(root->right, tmp->n);
		}
	}
	return (root);
}
