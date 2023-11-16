#include "monty.h"

/**
 * top_pop - The opcode to swap the top two elements of the stack.
 *
 * @stack: Pointer to pointer to the top element of the stack.
 * @line_number: The number of the line were there is the opcode.
 */
void top_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_node();
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	*stack = aux->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(aux);
}
