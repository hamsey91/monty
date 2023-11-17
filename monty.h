#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_fun)(stack_t **, unsigned int);

/*Prototypes*/

void fileOpen(char *file_name);
void fileRead(FILE *);
int _tokenize(char *buffer, int line_number, int format);
void op_fun_search(char *, char *, int, int);
void op_fun_call(op_fun, char *, char *, int, int);
int len_chars(FILE *);
stack_t *allocate_node(int n);
void push_to_top(stack_t **, unsigned int);
void print_all(stack_t **, unsigned int);
void _enqueue(stack_t **, unsigned int);
void print_top(stack_t **, unsigned int);
void top_pop(stack_t **, unsigned int);
void swap_top(stack_t **, unsigned int);
void add_top(stack_t **, unsigned int);
void _nop(stack_t **, unsigned int);
void sub_top(stack_t **, unsigned int);
void div_top(stack_t **, unsigned int);
void mul_top(stack_t **, unsigned int);
void mod_top(stack_t **, unsigned int);
void p_char(stack_t **, unsigned int);
void p_str(stack_t **, unsigned int);
void rot_l(stack_t **, unsigned int);
void rot_r(stack_t **, unsigned int);
void free_node(void);

#endif
