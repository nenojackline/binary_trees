#include "binary_trees.h"

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node
 *         NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *fnflip;
	int size, fnleaves, fnsub, fnbit, level, fntmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	fnleaves = size;
	for (level = 0, fnsub = 1; fnleaves >= fnsub; fnsub *= 2, level++)
		fnleaves -= fnsub;
	/* subtract all nodes except for bottom-most level */

	for (fnbit = 1 << (level - 1); fnbit != 1; fnbit >>= 1)
		tree = fnleaves & fnbit ? tree->right : tree->left;
	/*
	 * Traverse tree to first empty slot based on the binary
	 * representation of the number of fnleaves.
	 * If there are 12 nodes in a complete tree, there are 5 fnleaves on
	 * the 4th tier of the tree. 5 is 101 in binary. 1 corresponds to
	 * right, 0 to left.
	 * The first empty node is 101 == RLR, *root->right->left->right
	 */

	new = binary_tree_node(tree, value);
	fnleaves & 1 ? (tree->right = new) : (tree->left = new);

	fnflip = new;
	for (; fnflip->parent && (fnflip->n > fnflip->parent->n);
			fnflip = fnflip->parent)
	{
		fntmp = fnflip->n;
		fnflip->n = fnflip->parent->n;
		fnflip->parent->n = fntmp;
		new = new->parent;
	}
	/* Flip values with parent until parent value exceeds new value */

	return (new);
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
