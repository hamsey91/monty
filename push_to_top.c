#include "monty.h"

/**
 * push_to_top - The opcode to push an element to the stack.
 *
 * @n_node: Pointer to pointer to the new node.
 * @l_num: The number of the line were there is the opcode
 */

void push_to_top(stack_t **n_node, __attribute__((unused))unsigned int l_num)
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
	head = *n_node;
	head->next = aux;
	aux->prev = head;
}
