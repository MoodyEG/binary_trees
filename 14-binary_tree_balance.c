#include "binary_trees.h"
/**
 * binary_tree_balance - function that measures
 * the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree
 * to measure the balance factor
 * Return: the balance factor, or 0 if the tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		balance += 1;
	if (tree->right != NULL)
		balance -= 1;
	balance += binary_tree_height(tree->left)
	- binary_tree_height(tree->right);
	return (balance);
}
