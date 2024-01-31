#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: the given array
 * @size: the number of element in the array
 *
 * Return: pointer to the root node of the created BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *tree = NULL;

	for (i = 0; i < size; i++)
		bst_insert(&tree, array[i]);

	return (tree);
}
