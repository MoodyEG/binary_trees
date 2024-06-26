#include "binary_trees.h"
/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: a pointer to the node containing a value equals to value
 * or NULL if tree is NULL or if nothing is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	while (tree)
	{
		if (tree->n < value)
			tree = tree->right;
		else if (tree->n > value)
			tree = tree->left;
		else
			return ((bst_t *)tree);
	}
	return (NULL);
}
