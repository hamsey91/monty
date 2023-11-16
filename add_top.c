#include "monty.h"

/**
 * add_top - The opcode to add the top two elements of the stack.
 *
 * @stack: Pointer to pointer to the top element of the stack.
 * @line_number: The number of the line were there is the opcode.
 */
void add_top(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "add");
		free_node();
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
