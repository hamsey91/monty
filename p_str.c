#include "monty.h"

/**
 * p_str - The function that prints the string starting
 *at the top of the stack.
 *
 * @stack: Pointer to pointer to the top element of the stack.
 * @l_num: The number of the line were there is the opcode.
 */
void p_str(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	int std_code;
	stack_t *aux;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	aux = *stack;
	while (aux != NULL)
	{
		std_code = aux->n;
		if (std_code <= 0 || std_code > 127)
			break;
		printf("%c", std_code);
		aux = aux->next;
	}
	printf("\n");
}
