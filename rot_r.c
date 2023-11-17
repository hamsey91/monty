#include "monty.h"

/**
 * rot_r - The function that rotates the stack to the bottom.
 *
 * @stack: Pointer to pointer to the top element of the stack.
 * @l_num: The number of the line were there is the opcode.
 */
void rot_r(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	stack_t *aux;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	aux = *stack;

	while (aux->next != NULL)
		aux = aux->next;

	aux->next = *stack;
	aux->prev->next = NULL;
	aux->prev = NULL;
	(*stack)->prev = aux;
	(*stack) = aux;
}
