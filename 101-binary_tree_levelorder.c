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
 * print_level - function that prints the level
 * @tree: a pointer to the root node of the tree to traverse
 * @level: the level of the nodes
 * @func: a pointer to a function to call for each node
 * Return: no return
 */
void print_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 0)
		func(tree->n);
	else
	{
		print_level(tree->left, --level, func);
		print_level(tree->right, level, func);
	}
}
/**
 * binary_tree_levelorder - function that goes through
 * a binary tree using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 * Return: no return
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i, level;

	if (tree == NULL || func == NULL)
		return;
	level = binary_tree_height(tree);
	for (i = 0; i <= level; i++)
		print_level(tree, i, func);
}
