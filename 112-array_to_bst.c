#include "binary_trees.h"
/**
 * array_to_bst - function that builds a Binary Search Tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: a pointer to the root node of the created BST,
 * or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root = NULL;

	if (array == NULL || size <= 0)
		return (NULL);
	while (i < size)
	{
		if (i == 0)
			root = bst_insert(&root, array[i]);
		else
			bst_insert(&root, array[i]);
		i++;
	}
	return (root);
}
