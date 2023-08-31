#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverst a binary tree using level-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, fnmaxlevel;

	if (!tree || !func)
		return;

	fnmaxlevel = binary_tree_height(tree) + 1;

	for (level = 1; level <= fnmaxlevel; level++)
		fnbtlo_helper(tree, func, level);
}

/**
 * fnbtlo_helper - goes through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 * @level: the level of the tree to call func upon
 */
void fnbtlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		fnbtlo_helper(tree->left, func, level - 1);
		fnbtlo_helper(tree->right, func, level - 1);
	}
}

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
