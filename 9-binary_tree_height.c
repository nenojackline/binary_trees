#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t fnheight_l = 0;
	size_t fnheight_r = 0;

	if (!tree)
		return (0);

	fnheight_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	fnheight_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (fnheight_l > fnheight_r ? fnheight_l : fnheight_r);
}
