#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t fnheight_l = 0;
	size_t fnheight_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		fnheight_l = 1 + tree_height(tree->left);

	if (tree->right)
		fnheight_r = 1 + tree_height(tree->right);

	if (fnheight_l > fnheight_r)
		return (fnheight_l);
	return (fnheight_r);
}
/**
 * tree_size_h - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t fnheight_l = 0;
	size_t fnheight_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		fnheight_l = 1 + tree_size_h(tree->left);

	if (tree->right)
		fnheight_r = 1 + tree_size_h(tree->right);

	return (fnheight_l + fnheight_r);
}

/**
 * _preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last note in traverse
 * @height: height of tree
 *
 * Return: No Return
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *fntmp1, *fntmp2;

	if (!root)
		return;

	fntmp1 = root;

	while (1)
	{
		if (!fntmp1->left)
			break;
		if (!fntmp1->right)
			fntmp2 = fntmp1->left;
		else
		{
			if (fntmp1->left->n > fntmp1->right->n)
				fntmp2 = fntmp1->left;
			else
				fntmp2 = fntmp1->right;
		}
		if (fntmp1->n > fntmp2->n)
			break;
		value = fntmp1->n;
		fntmp1->n = fntmp2->n;
		fntmp2->n = value;
		fntmp1 = fntmp2;
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: a double pointer to the root node of heap
 *
 * Return: the value stored in the root node
 *         0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *fnheap_r, *node;

	if (!root || !*root)
		return (0);
	fnheap_r = *root;
	value = fnheap_r->n;
	if (!fnheap_r->left && !fnheap_r->right)
	{
		*root = NULL;
		free(fnheap_r);
		return (value);
	}

	_preorder(fnheap_r, &node, tree_height(fnheap_r));

	fnheap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(fnheap_r);
	*root = fnheap_r;
	return (value);
}
