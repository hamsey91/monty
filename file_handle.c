#include "monty.h"

/**
 * fileOpen - Function to open opens a file
 *
 * @file_name: the PAth were the file is located.
 *
 * Return: Nothing
 */

void fileOpen(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		free_node();
		exit(EXIT_FAILURE);
	}

	fileRead(fd);
	fclose(fd);
}


/**
 * fileRead - The function that reads a file.
 *
 * @fd: Pointer to the file descriptor
 *
 * Return: Nothing.
 */

void fileRead(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t length = 0;

	for (line_number = 1; getline(&buffer, &length, fd) != -1; line_number++)
	{
		format = _tokenize(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * _tokenize - The function that Split each line into tokens.
 *
 * @buffer: the concerned line in the file.
 * @line_number: The number of the line were there is the opcode.
 * @format: If 0 nodes will be entered as a Stack,
 *	If 1 nodes will be entered as a Queue.
 *
 * Return: 0 if the opcode is Stack, 1 if it is a Queue.
 */

int _tokenize(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delimiter = "\n ";

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_node();
		exit(EXIT_FAILURE);
	}

	opcode = strtok(buffer, delimiter);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delimiter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	op_fun_search(opcode, value, line_number, format);
	return (format);
}
