#include "monty.h"

/**
 * swap_top - The opcode to swap the top two elements of the stack.
 *
 * @stack: Pointer to pointer to the top node of the stack.
 * @line_number: The number of the line were there is the opcode
 */
void swap_top(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "swap");
		free_node();
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->next;
	(*stack)->next = aux->next;
	if (aux->next != NULL)
		aux->next->prev = *stack;
	aux->next = *stack;
	(*stack)->prev = aux;
	aux->prev = NULL;
	*stack = aux;
}
