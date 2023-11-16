#include "monty.h"

/**
 * free_node - The function to Free nodes in the stack.
 */
void free_node(void)
{
	stack_t *aux;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}
