#include "binary_trees.h"
/**
 * rchild - function that rmoves a node (case node->right)
 * @root: a pointer to the root node of the tree to remove a node
 * @node: a pointer to the node that would be deleted
 * Return: a pointer to the new root node of the tree
 * had ton of a help for this one
 */
bst_t *rchild(binary_tree_t *root, binary_tree_t *node)
{
	node->right->left = node->left;
	node->right->parent = node->parent;
	if (node->parent)
	{
		if (node == node->parent->left)
			node->parent->left = node->right;
		if (node == node->parent->right)
			node->parent->right = node->right;
	}
	if (node->left)
		node->left->parent = node->right;
	if (node == root)
		root = node->right;
	free(node);
	return (root);
}
/**
 * rlchild - function that rmoves a node (case node->right->left)
 * @root: a pointer to the root node of the tree to remove a node
 * @node: a pointer to the node that would be deleted
 * Return: a pointer to the new root node of the tree
 */
bst_t *rlchild(binary_tree_t *root, binary_tree_t *node)
{
	node->right->left->right = node->right;
	node->right->left->parent = node->parent;
	node->right->left->left = node->left;
	if (node->left)
		node->left->parent = node->right->left;
	node->right->parent = node->right->left;
	if (node == root)
		root = node->right->left;
	else
	{
		if (node == node->parent->right)
			node->parent->right = node->right->left;
		if (node == node->parent->left)
			node->parent->left = node->right->left;
	}
	node->right->left = NULL;
	free(node);
	return (root);
}
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
/**
 * bst_remove - function that removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree to remove a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;

	node = bst_search(root, value);
	if (node != NULL)
	{
		if (binary_tree_is_leaf(node))
		{
			if (node == node->parent->left)
				node->parent->left = NULL;
			else if (node == node->parent->right)
				node->parent->right = NULL;
			free(node);
			return (root);
		}
		if (node->right && node->right->left)
			root = rlchild(root, node);
		else if (node->right)
			root = rchild(root, node);
		else
		{
			if (node->parent)
				node->parent->right = node->left;
			node->left->parent = node->parent;
			if (root == node)
				root = node->left;
			free(node);
		}
	}
	return (root);
}
