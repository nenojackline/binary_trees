#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 *
 * @parent: is a pointer to the node to insert the left-child in
 * @value:  is the value to store in the new node
 *
 * Description - If parent already has a left-child, the new node must
 *				take its place, and the old left-child must be set as
 *				the left-child of the new node.
 *
 * Return: a pointer to the created node, or NULL on failure or if
 *			parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *fnNew;

	if (!parent)
		return (NULL);

	fnNew = malloc(sizeof(binary_tree_t));
	if (!fnNew)
		return (NULL);

	fnNew->n = value;
	fnNew->parent = parent;
	fnNew->right = NULL;
	fnNew->left = parent->left;
	parent->left = fnNew;
	if (fnNew->left)
		fnNew->left->parent = fnNew;
	return (fnNew);
}
