#include "monty.h"

/**
 * _rotl - rotates the first element to the bottom and  the second to the top
 *
 * @headptr: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _rotl(stack_t **headptr, unsigned int line_num)
{
	stack_t *current1 = NULL;
	stack_t *current2 = NULL;
	(void)line_num;

	if (*headptr == NULL)
		return;

	if ((*headptr)->next == NULL)
		return;

	current1 = (*headptr)->next;
	current2 = *headptr;

	for (; current2->next != NULL; current2 = current2->next)
		;

	current1->prev = NULL;
	current2->next = *headptr;
	(*headptr)->next = NULL;
	(*headptr)->prev = current2;
	*headptr = current1;
}

/**
 * _rotr - reverse the stack
 *
 * @headptr: head of the linked list
 * @line_num: line number
 * Return: no return
 */
void _rotr(stack_t **headptr, unsigned int line_num)
{
	stack_t *current = NULL;
	(void)line_num;

	if (*headptr == NULL)
		return;

	if ((*headptr)->next == NULL)
		return;

	current = *headptr;

	for (; current->next != NULL; current = current->next)
		;

	current->prev->next = NULL;
	current->next = *headptr;
	current->prev = NULL;
	(*headptr)->prev = current;
	*headptr = current;
}
