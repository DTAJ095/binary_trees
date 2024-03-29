#include "binary_trees.h"

/**
 * binary_tree_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	const binary_tree_t *first_anc, *second_anc;

	first_anc = first;

	while (first_anc)
	{
		second_anc = second;
		while (second_anc)
		{
			if (first_anc == second_anc)
				return ((binary_tree_t *)first_anc);
			second_anc = second_anc->parent;
		}
		first_anc = first_anc->parent;
	}
	return (NULL);
}
