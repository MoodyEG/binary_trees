#include "binary_trees.h"
/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: the height, or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0, hr = 0, hf = 0;

	if (tree == NULL)
		return (0);
	if (tree->right != NULL || tree->left != NULL)
		height++;
	hr += binary_tree_height(tree->right);
	hf += binary_tree_height(tree->left);
	if (hr > hf)
		height += hr;
	else
		height += hf;
	return (height);
}
