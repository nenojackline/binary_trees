#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures height of a binary tree for a bal tree
 * @tree: tree to go through
 * Return: the height
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t fnl = 0;
	size_t fnr = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			fnl = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
			fnr = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
		}
		return ((fnl > fnr) ? fnl : fnr);
	}
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: tree to go through
 * Return: balanced factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, fntotal = 0;

	if (tree)
	{
		left = ((int)binary_tree_height_b(tree->left));
		right = ((int)binary_tree_height_b(tree->right));
		fntotal = left - right;
	}
	return (fntotal);
}
