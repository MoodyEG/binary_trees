#include "binary_trees.h"
/**
 * binary_tree_rotate_right - function that
 * performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (tree == NULL || tree->left == NULL)
		return (tree);
	root = tree->left;
	if (root->right)
		tree->left = root->right;
	else
		tree->left = NULL;
	root->right = tree;
	root->parent = tree->parent;
	tree->parent = root;
	if (tree->left)
		tree->left->parent = tree;
	return (root);
}
