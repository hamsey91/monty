#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry point
 *
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: 0
 */

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_node();
		exit(EXIT_FAILURE);
	}
	fileOpen(av[1]);
	free_node();
	return (0);
}
