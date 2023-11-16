#include "monty.h"

/**
 * print_top - The opcode to print the value at the top of the stack.
 *
 * @stack: Pointer to pointer to the top node of the stack.
 * @line_number: The number of the line were there is the opcode
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_node();
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}
