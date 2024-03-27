#include "binary_trees.h"
/**
 * binary_tree_rotate_left - function that
 * performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (tree == NULL || tree->right == NULL)
		return (tree);
	root = tree->right;
	if (root->left)
		tree->right = root->left;
	else
		tree->right = NULL;
	root->left = tree;
	root->parent = tree->parent;
	tree->parent = root;
	if (tree->right)
		tree->right->parent = tree;
	return (root);
}
