#include "monty.h"

/**
 * _queue - sets the format of the data to a queue (FIFO)
 *
 * @headptr: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _queue(stack_t **headptr, unsigned int line_num)
{
	(void)headptr;
	(void)line_num;

	param.lifo = 0;
}

/**
 * _stack - sets the format fo the data to a stack (LIFO)
 *
 * @headptr: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _stack(stack_t **headptr, unsigned int line_num)
{
	(void)headptr;
	(void)line_num;

	param.lifo = 1;
}

/**
 * _add - adds the top two elements of the stack
 *
 * @headptr: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _add(stack_t **headptr, unsigned int line_num)
{
	int m = 0;
	stack_t *current = NULL;

	current = *headptr;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_num);
		freeParam();
		exit(EXIT_FAILURE);
	}

	current = (*headptr)->next;
	current->n += (*headptr)->n;
	_pop(headptr, line_num);
}

/**
 * _nop - doesn't do anythinhg
 *
 * @headptr: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _nop(stack_t **headptr, unsigned int line_num)
{
	(void)headptr;
	(void)line_num;
}

/**
 * _sub - subtracts the top element to the second top element of the stack
 *
 * @headptr: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _sub(stack_t **headptr, unsigned int line_num)
{
	int m = 0;
	stack_t *current = NULL;

	current = *headptr;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_num);
		freeParam();
		exit(EXIT_FAILURE);
	}

	current = (*headptr)->next;
	current->n -= (*headptr)->n;
	_pop(headptr, line_num);
}
