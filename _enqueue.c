#include "monty.h"

/**
 * _enqueue - The opcode to push an element to the Queue.
 *
 * @n_node: Pointer to pointer to the new node.
 * @l_num: The number of the line were there is the opcode
 */
void _enqueue(stack_t **n_node, __attribute__((unused))unsigned int l_num)
{
	stack_t *aux;

	if (n_node == NULL || *n_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n_node;
		return;
	}
	aux = head;
	while (aux->next != NULL)
		aux = aux->next;

	aux->next = *n_node;
	(*n_node)->prev = aux;
}
