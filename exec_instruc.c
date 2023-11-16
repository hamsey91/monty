#include "monty.h"

/**
 * op_fun_search - Function to check for the suitable function for the opcode.
 *
 * @opcode: the opcode
 * @value: value representing the argument of the opcode
 * @line_number: The number of the line were there is the opcode.
 * @format: If 0 nodes will be entered as a Stack,
 *	If 1 nodes will be entered as a Queue.
 *
 * Return: Nothing.
 */
void op_fun_search(char *opcode, char *value, int line_number, int format)
{
	int i;
	int status;

	instruction_t list_op_fun[] = {
		{"push", push_to_top},
		{"pall", print_all},
		{"pint", print_top},
		{"pop", top_pop},
		{"nop", _nop},
		{"swap", swap_top},
		{"add", add_top},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (status = 1, i = 0; list_op_fun[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, list_op_fun[i].opcode) == 0)
		{
			op_fun_call(list_op_fun[i].f, opcode, value, line_number, format);
			status = 0;
		}
	}
	if (status == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		free_node();
		exit(EXIT_FAILURE);
	}
}


/**
 * op_fun_call - the function to Call the appropriate function.
 *
 * @fun: Pointer to the called function.
 * @opc: the opcode
 * @val: Numeric value representing the argument of the opcode.
 * @line_number: The number of the line were there is the opcode.
 * @form: If 0 nodes will be entered as a Stack,
 *	If 1 nodes will be entered as a Queue.
 */
void op_fun_call(op_fun fun, char *opc, char *val, int line_number, int form)
{
	stack_t *node;
	int status;
	int i;

	status = 1;
	if (strcmp(opc, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			status = -1;
		}
		if (val == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_node();
			exit(EXIT_FAILURE);
		}
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_node();
				exit(EXIT_FAILURE);
			}
		}
		node = allocate_node(atoi(val) * status);
		if (form == 0)
			fun(&node, line_number);
		if (form == 1)
			_enqueue(&node, line_number);
	}
	else
		fun(&head, line_number);
}
