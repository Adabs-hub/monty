#include "monty.h"

/**
 * _div - divides the second element by the top element of the stack
 *
 * @headptr: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _div(stack_t **headptr, unsigned int line_num)
{
	int m = 0;
	stack_t *current = NULL;

	current = *headptr;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_num);
		freeParam();
		exit(EXIT_FAILURE);
	}

	if ((*headptr)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_num);
		freeParam();
		exit(EXIT_FAILURE);
	}

	current = (*headptr)->next;
	current->n /= (*headptr)->n;
	_pop(headptr, line_num);
}

/**
 * _mul - multiplies the top element to the second top element of the stack
 *
 * @headptr: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _mul(stack_t **headptr, unsigned int line_num)
{
	int m = 0;
	stack_t *current = NULL;

	current = *headptr;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_num);
		freeParam();
		exit(EXIT_FAILURE);
	}

	current = (*headptr)->next;
	current->n *= (*headptr)->n;
	_pop(headptr, line_num);
}

/**
 * _mod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @headptr: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _mod(stack_t **headptr, unsigned int line_num)
{
	int m = 0;
	stack_t *current = NULL;

	current = *headptr;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_num);
		freeParam();
		exit(EXIT_FAILURE);
	}

	if ((*headptr)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_num);
		freeParam();
		exit(EXIT_FAILURE);
	}

	current = (*headptr)->next;
	current->n %= (*headptr)->n;
	_pop(headptr, line_num);
}
/**
 * _pchar - print the char value of the first element
 *
 * @headptr: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _pchar(stack_t **headptr, unsigned int line_num)
{
	if (headptr == NULL || *headptr == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_num);
		freeParam();
		exit(EXIT_FAILURE);
	}
	if ((*headptr)->n < 0 || (*headptr)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_num);
		freeParam();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*headptr)->n);
}

/**
 * _pstr - prints the string of the stack
 *
 * @headptr: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _pstr(stack_t **headptr, unsigned int line_num)
{
	stack_t *current;
	(void)line_num;

	current = *headptr;

	while (current && current->n > 0 && current->n < 128)
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
