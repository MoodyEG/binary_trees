#include "binary_trees.h"
/**
 * bst_ins - function that inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_ins(bst_t **tree, int value)
{
	bst_t *temp;

	temp = *tree;
	if (value < temp->n)
	{
		if (temp->left == NULL)
		{
			temp->left = binary_tree_node(temp, value);
			return (temp->left);
		}
		else
			return (bst_ins(&(temp->left), value));
	}
	if (value > temp->n)
	{
		if (temp->right == NULL)
		{
			temp->right = binary_tree_node(temp, value);
			return (temp->right);
		}
		else
			return (bst_ins(&(temp->right), value));
	}
	return (NULL);
}
/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	return (bst_ins(tree, value));
}
