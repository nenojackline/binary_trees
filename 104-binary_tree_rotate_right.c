#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Function that  rotates right the binary tree.
 * @tree: The root node of the three
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *fnpivot;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	fnpivot = tree->left;
	tree->left = fnpivot->right;
	if (fnpivot->right != NULL)
	{
		fnpivot->right->parent = tree;
	}
	fnpivot->right = tree;
	fnpivot->parent = tree->parent;
	tree->parent = fnpivot;
	return (fnpivot);
}
