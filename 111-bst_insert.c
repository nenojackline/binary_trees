#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: A pointer to the created node
 *         NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *fntmp = NULL;
	bst_t *fnsecond = NULL;
	bst_t *fnnew = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	fntmp = *tree;
	while (fntmp)
	{
		fnsecond = fntmp;
		if (value < fntmp->n)
			fntmp = fntmp->left;
		else if (value > fntmp->n)
			fntmp = fntmp->right;
		else if (value == fntmp->n)
			return (NULL);
	}

	fnnew = binary_tree_node(NULL, value);
	if (fnsecond == NULL)
		fnsecond = fnnew;
	else if (value < fnsecond->n)
	{
		fnsecond->left = fnnew;
		fnnew->parent = fnsecond;
	}
	else
	{
		fnsecond->right = fnnew;
		fnnew->parent = fnsecond;
	}

	return (fnnew);
}
