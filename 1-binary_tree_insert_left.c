#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node at the left-child node
 * @parent: the parent node
 * @value: the node value
 *
 * Return: pointer to the new node of NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = parent->left;
	new_node->right = NULL;
	if (parent->left != NULL)
		parent->parent->parent = new_node;
	parent->left = new_node;

	return (new_node);
}
