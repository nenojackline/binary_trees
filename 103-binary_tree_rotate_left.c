#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that  rotates left the binary tree.
 * @tree: The root node of the three
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *fnpivot;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	fnpivot = tree->right;
	tree->right = fnpivot->left;
	if (fnpivot->left != NULL)
	{
		fnpivot->left->parent = tree;
	}
	fnpivot->left = tree;
	fnpivot->parent = tree->parent;
	tree->parent = fnpivot;
	return (fnpivot);
}
