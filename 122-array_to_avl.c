#include "binary_trees.h"
/**
 * array_to_avl - a function that builds an AVL tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: a pointer to the root node of the created AVL,
 * or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root = NULL;

	if (array == NULL || size <= 0)
		return (NULL);
	while (i < size)
	{
		if (i == 0)
			root = avl_insert(&root, array[i]);
		else
			avl_insert(&root, array[i]);
		i++;
	}
	return (root);
}
