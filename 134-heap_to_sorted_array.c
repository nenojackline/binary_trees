#include "binary_trees.h"

/**
 * tree_size - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t fnheight_l = 0;
	size_t fnheight_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		fnheight_l = 1 + tree_size(tree->left);

	if (tree->right)
		fnheight_r = 1 + tree_size(tree->right);

	return (fnheight_l + fnheight_r);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 * @heap: a pointer to the root node of the heap to convert
 * @size: an address to store the size of the array
 *
 * Return: the generated array
 *         NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int b, *c = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	c = malloc(sizeof(int) * (*size));

	if (!c)
		return (NULL);

	for (b = 0; heap; b++)
		c[b] = heap_extract(&heap);

	return (c);
}
