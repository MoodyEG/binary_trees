#include "binary_trees.h"
/**
 * binary_tree_sibling - function that finds the sibling of a node
 * @node: a pointer to the node to find the sibling
 * Return: a pointer to the sibling node
 * or NULL if node or parent are NULL , or there is no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
	if (node->parent->left != NULL && node->parent->left != node)
		return (node->parent->left);
	if (node->parent->right != NULL && node->parent->right != node)
		return (node->parent->right);
	return (NULL);
}
