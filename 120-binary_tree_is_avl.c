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
	if ((tree->left == NULL && tree->right == NULL))
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
 * is_avl - function that finds the sibling of a node
 * @tree: a pointer to the root node of the tree to check
 * Return: return 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int is_avl(const binary_tree_t *tree)
{
	int b = 0;

	if (tree == NULL)
		return (1);
	if (!is_bst(tree))
		return (0);
	if (tree->left != NULL)
		b += 1;
	if (tree->right != NULL)
		b -= 1;
	b += binary_tree_height(tree->left)
	- binary_tree_height(tree->right);
	if (abs(b) > 1)
		return (0);
	return (is_avl(tree->left) && is_avl(tree->right));
}
/**
 * binary_tree_is_avl - function that finds the sibling of a node
 * @tree: a pointer to the root node of the tree to check
 * Return: return 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl(tree));
}
