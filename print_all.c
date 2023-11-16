#include "monty.h"

/**
 * print_all - The opcode to print all the values on the stack
 *		starting from the top of the stack.
 *
 * @stack: Pointer to pointer to the top node of the stack.
 * @line_number: The number of the line were there is the opcode
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	aux = *stack;
	while (aux != NULL)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
