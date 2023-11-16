#include "monty.h"

/**
 * allocate_node - function that aloocate memory in to the node.
 *
 * @n: Integer value to put in to the node.
 *
 * Return: Pointer to the created node if succeed, Otherwise NULL.
 */
stack_t *allocate_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_node();
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
