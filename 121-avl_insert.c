#include "binary_trees.h"
/**
 * what_league_needs - balance is what it needs
 * this functions balances the tree by rotating
 * @tree: a double pointer to the root node of the AVL tree
 * @value: the value to store in the node to be inserted
 * Return: no return
 */
void what_league_needs(avl_t **tree, int value)
{
	int b;

	b = binary_tree_balance(*tree);
	if (b > 1 && value < (*tree)->left->n)
	{
		*tree = binary_tree_rotate_right(*tree);
		return;
	}
	if (b > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
		return;
	}
	if (b < -1 && value > (*tree)->right->n)
	{
		*tree = binary_tree_rotate_left(*tree);
		return;
	}
	if (b < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
		return;
	}

}
/**
 * avl_ins - function that inserts a value in an AVL Tree
 * @tree: a double pointer to the root node of
 * the AVL tree for inserting the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
avl_t *avl_ins(avl_t **tree, int value)
{
	avl_t *node;

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
		{
			node = avl_ins(&((*tree)->left), value);
			if (node)
				what_league_needs(tree, value);
			return (node);
		}
	}
	if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		else
		{
			node =  avl_ins(&((*tree)->right), value);
			if (node)
				what_league_needs(tree, value);
			return (node);
		}
	}
	return (NULL);
}
/**
 * avl_insert - function that inserts a value in an AVL Tree
 * @tree: a double pointer to the root node of
 * the AVL tree for inserting the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (*tree == NULL)
	{
		node = binary_tree_node(NULL, value);
		(*tree) = node;
	}
	else
		node = avl_ins(tree, value);
	return (node);
}
