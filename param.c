#include "monty.h"

/**
 * initialize_param - initialize param
 * Return: nothing
 */
void initialize_param(void)
{
	param.headptr = NULL;
	param.opcode = NULL;
	param.value = 0;
	param.top = -1;
	param.line_number = 0;
	param.readfd = NULL;
}


/**
 * freeParam - free param
 * Return: nothing
 */
void freeParam(void)
{
	if (param.opcode != NULL)
		free(param.opcode);
	if (param.headptr != NULL)
		free_dlistint(param.headptr);
	fclose(param.readfd);
}
