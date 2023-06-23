#include "monty.h"

/**
 * get_buildInFunc - get select build in function
 * @param: commands to run  (char)
 * Return: pointer to function pointer
 */

void (*get_opcodeFunc())(stack_t **, unsigned int)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	instruction_t func_arr[] = {
	{"push", _push},
	{"pall", _pall},
	{"pint", pint},
	{"pop", _pop},
	{"swap", _swap},
	{"NULL", NULL}
	};
	int i = 0;

	f = NULL;
	while (i < 7)
	{
		if ((strcmp(func_arr[i].opcode, param.opcode) == 0))
		{
			f = func_arr[i].f;
		}
		i++;
	}

	if (f != NULL)
		f(&param.headptr, param.line_number);
	else
	{
		freeParam();
		fprintf(stderr, "L%u: unknown instruction %s\n", param.line_number, param.opcode);
		exit(EXIT_FAILURE);
	}
return (0);
}
