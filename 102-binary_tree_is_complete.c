#include "binary_trees.h"
/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size.
 * Return: the size, or 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);
	size++;
	size += binary_tree_size(tree->right);
	size += binary_tree_size(tree->left);
	return (size);
}
/**
 * is_complete - function that checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to measure the size.
 * @number: number of current node
 * @size: size of the tree
 * Return: 1 if complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t number, size_t size)
{
	if (tree == NULL)
		return (1);
	if (number >= size)
		return (0);
	return (is_complete(tree->left, (number * 2) + 1, size) &&
	is_complete(tree->right, (number * 2) + 2, size));
}
/**
 * binary_tree_is_complete - function that
 * checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to measure the size.
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);
	size = binary_tree_size(tree);
	return (is_complete(tree, 0, size));
}
