#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>

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

/**
 * struct data - data
 * @readfd: read socket descripter
 */
typedef struct data
{
	char *headptr;
	char *opcode;
	int value;
	int top;
	unsigned int line_number;
	FILE *readfd;

} data_t;

extern data_t param;

	/*getfunc.c*/
	int (*get_opcodeFunc(void))(stack_t **, unsigned int);
	void freeParam(void);
	/*main.c*/
	int isInt(char *str);
	char *trim_word(char **str);

	/*param.c*/
	void initialize_param(void);
	void freeParam(void);

	/*buildinfunc.c*/
	void _push(stack_t **headptr, unsigned int line_count);
	void _pall(stack_t **headptr, unsigned int line_count);
	void _pop(stack_t **headptr, unsigned int line_count);
	void _swap(stack_t **headptr, unsigned int line_count);
	void pint(stack_t **headptr, unsigned int line_count);

	/*func_d_linkedlist*/
	stack_t *add_dnodeint_end(stack_t **head, const int n);
	stack_t *add_dnodeint(stack_t **head, const int n);
	void free_dlistint(stack_t *head);


	

#endif /*_MONTY_H*/
