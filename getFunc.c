#include "monty.h"

/**
 * get_buildInFunc - get select build in function
 * @param: commands to run  (char)
 * Return: pointer to function pointer
 */

int (*get_opcodeFunc())(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
	{"push", push},
	{"pall", pall},
	{"NULL", NULL}
	}
	int i = 0;

	while (i < 6)
	{
		if ((strcmp(func_arr[i].opcode, param.opcode) == 0))
		{
			return (func_arr[i].f);
		}
		i++;
	}
	freeParam(param);
	fprintf(stderr, "L%u: unknown instruction %s", param.line_number, param.opcode);
	exit(EXIT_FAILURE);
	return (0);
}
