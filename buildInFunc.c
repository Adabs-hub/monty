#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @headptr: head of the linked list
 * @line_num: line number
 * Return: no return
 */
void _push(stack_t **headptr, unsigned int line_num)
{
	int n, j;

	if (!param.arg)
	{
		dprintf(2, "L%u: ", line_num);
		dprintf(2, "usage: push integer\n");
		freeParam();
		exit(EXIT_FAILURE);
	}

	for (j = 0; param.arg[j] != '\0'; j++)
	{
		if (!isdigit(param.arg[j]) && param.arg[j] != '-')
		{
			dprintf(2, "L%u: ", line_num);
			dprintf(2, "usage: push integer\n");
			freeParam();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(param.arg);

	if (param.lifo == 1)
		add_dnodeint(headptr, n);
	else
		add_dnodeint_end(headptr, n);
}

/**
 * _pall - prints all values on the stack
 *
 * @headptr: head of the linked list
 * @line_num: line numbers
 * Return: no return
 */
void _pall(stack_t **headptr, unsigned int line_num)
{
	stack_t *current;
	(void)line_num;

	current = *headptr;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @headptr: head of the linked list
 * @line_num: line number
 * Return: no return
 */
void _pint(stack_t **headptr, unsigned int line_num)
{
	(void)line_num;

	if (*headptr == NULL)
	{
		dprintf(2, "L%u: ", line_num);
		dprintf(2, "can't pint, stack empty\n");
		freeParam();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*headptr)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @headptr: head of the linked list
 * @line_num: line number
 * Return: no return
 */
void _pop(stack_t **headptr, unsigned int line_num)
{
	stack_t *current;

	if (headptr == NULL || *headptr == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_num);
		freeParam();
		exit(EXIT_FAILURE);
	}
	current = *headptr;
	*headptr = (*headptr)->next;
	free(current);
}

/**
 * _swap - swaps the top two elements of the stack
 *
 * @headptr: head of the linked list
 * @line_num: line number
 * Return: no return
 */
void _swap(stack_t **headptr, unsigned int line_num)
{
	int m = 0;
	stack_t *current = NULL;

	current = *headptr;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_num);
		freeParam();
		exit(EXIT_FAILURE);
	}

	current = *headptr;
	*headptr = (*headptr)->next;
	current->next = (*headptr)->next;
	current->prev = *headptr;
	(*headptr)->next = current;
	(*headptr)->prev = NULL;
}
