#include "monty.h"

/**
 * p_char - The function that prints the char at the top of the stack.
 *
 * @stack: Pointer to pointer to the top element of the stack.
 * @line_number: The number of the line were there is the opcode.
 */
void p_char(stack_t **stack, unsigned int line_number)
{
	int std_code;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_node();
		exit(EXIT_FAILURE);
	}

	std_code = (*stack)->n;
	if (std_code < 0 || std_code > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_node();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", std_code);
}
