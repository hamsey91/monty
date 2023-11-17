#include "monty.h"

/**
 * rot_l - The function that rotates the stack to the top.
 *
 * @stack: Pointer to pointer to the top element of the stack.
 * @l_num: The number of the line were there is the opcode.
 */
void rot_l(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	stack_t *aux;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	aux = *stack;

	while (aux->next != NULL)
		aux = aux->next;

	aux->next = *stack;
	(*stack)->prev = aux;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
