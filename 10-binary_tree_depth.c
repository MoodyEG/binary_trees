#include "binary_trees.h"
/**
 * binary_tree_depth - function that measures the depth
 * @tree: a pointer to the node to measure the depth
 * Return: the depth, or 0 if the tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree != NULL)
	{
		if (tree->parent != NULL)
			depth++;
		tree = tree->parent;
	}
	return (depth);
}
