#include "monty.h"

/**
 * mul_top - The function that multiplies the second top element of
 *	the stack with the top element of the stack.
 *
 * @stack: Pointer to pointer to the top element of the stack.
 * @line_number: The number of the line were there is the opcode.
 */
void mul_top(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "mul");
		free_node();
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
