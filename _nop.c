#include "monty.h"

/**
 * _nop - The opcode doesn’t do anything.
 *
 * @stack: Pointer to pointer to the top node of the stack.
 * @line_number: The number of the line were there is the opcode
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
