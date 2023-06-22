#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @headptr: head of the linked list
 * @line_count: line number
 * Return: no return
 */
void _push(stack_t **headptr, unsigned int line_count)
{
	int n, j;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", line_count);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			dprintf(2, "L%u: ", line_count);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(headptr, n);
	else
		add_dnodeint_end(headptr, n);
}

/**
 * _pall - prints all values on the stack
 *
 * @headptr: head of the linked list
 * @line_count: line numbers
 * Return: no return
 */
void _pall(stack_t **headptr, unsigned int line_count)
{
	stack_t *aux;
	(void)line_count;

	aux = *headptr;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @headptr: head of the linked list
 * @line_count: line number
 * Return: no return
 */
void pint(stack_t **headptr, unsigned int line_count)
{
	(void)line_count;

	if (*headptr == NULL)
	{
		dprintf(2, "L%u: ", line_count);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*headptr)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @headptr: head of the linked list
 * @line_count: line number
 * Return: no return
 */
void _pop(stack_t **headptr, unsigned int line_count)
{
	stack_t *aux;

	if (headptr == NULL || *headptr == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_count);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *headptr;
	*headptr = (*headptr)->next;
	free(aux);
}

/**
 * _swap - swaps the top two elements of the stack
 *
 * @headptr: head of the linked list
 * @line_count: line number
 * Return: no return
 */
void _swap(stack_t **headptr, unsigned int line_count)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *headptr;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_count);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = *headptr;
	*headptr = (*headptr)->next;
	aux->next = (*headptr)->next;
	aux->prev = *headptr;
	(*headptr)->next = aux;
	(*headptr)->prev = NULL;
}
