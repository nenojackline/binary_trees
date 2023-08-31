#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the First node to find the ancestor
 * @second: a pointer to the Second node to find the ancestor
 *
 * Return: pointer to the ancestor node
 *         NULL if there is no ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t fndepth_first, fndepth_second;

	if (!first || !second)
		return (NULL);

	fndepth_first = binary_tree_depth(first);
	fndepth_second = binary_tree_depth(second);

	while (fndepth_first > fndepth_second)
	{
		first = first->parent;
		fndepth_first--;
	}
	while (fndepth_second > fndepth_first)
	{
		second = second->parent;
		fndepth_second--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: node to calculate the depth of
 *
 * Return: depth of the node
 *         0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t fndepth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		fndepth++;
		tree = tree->parent;
	}

	return (fndepth);
}
