#include "monty.h"

/**
 * mod_top - The function that computes the rest of the division of
 * the second top element of the stack by the top element of the stack.
 *
 * @stack: Pointer to pointer to the top element of the stack.
 * @line_number: The number of the line were there is the opcode.
 */
void mod_top(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "mod");
		free_node();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_node();
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
