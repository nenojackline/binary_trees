#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: array to create from
 * @size: size of the array
 *
 * Return: a pointer to the root node of the created AVL tree
 *         NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int b;
	avl_t *root = NULL;

	for (b = 0; b < size; b++)
		avl_insert(&root, array[b]);

	return (root);
}
