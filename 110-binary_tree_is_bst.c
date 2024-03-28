#include "binary_trees.h"
/**
 * binary_tree_is_leaf - a function that checks if a node is a leaf
 * @node: a pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0 or if NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if ((node->left == NULL && node->right == NULL))
		return (1);
	return (0);
}
/**
 * checkgp - function that checks
 * if the node is bigger/smaller than the grandparent
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if valid, and 0 otherwise
 */
int checkgp(const binary_tree_t *tree)
{
	binary_tree_t *pa, *papa;

	if (tree == NULL || tree->parent == NULL ||
	tree->parent->parent == NULL)
		return (1);
	pa = tree->parent;
	papa = pa->parent;
	while (pa && papa)
	{
		if (pa->n < papa->n && tree->n >= papa->n)
			return (0);
		if (pa->n > papa->n && tree->n <= papa->n)
			return (0);
		pa = pa->parent;
		papa = pa->parent;
	}
	return (1);
}
/**
 * is_bst - function that checks
 * if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (binary_tree_is_leaf(tree))
		return (1);
	if (tree->left && tree->left->n >= tree->n)
		return (0);
	if (tree->right && tree->right->n <= tree->n)
		return (0);
	if (!checkgp(tree->left) || !checkgp(tree->right))
		return (0);
	return (is_bst(tree->left) && is_bst(tree->right));
}
/**
 * binary_tree_is_bst - function that checks
 * if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst(tree));
}
