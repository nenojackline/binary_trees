#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect
 *         0 if the tree is not perfect
 *         0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t fnheight = 0;
	size_t fnnodes = 0;
	size_t fnpower = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	fnheight = binary_tree_height(tree);
	fnnodes = binary_tree_size(tree);

	fnpower = (size_t)fnPow_recursion(2, fnheight + 1);
	return (fnpower - 1 == fnnodes);
}

/**
 *fnPow_recursion - returns the value of a raised to the power of b
 *@a: the value to exponentiate
 *@b: the power to raise a to
 *Return: a to the power of b, or -1 if b is negative
 */

int fnPow_recursion(int a, int b)
{
	if (b < 0)
		return (-1);
	if (b == 0)
		return (1);
	else
		return (a * fnPow_recursion(a, b - 1));

}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
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
