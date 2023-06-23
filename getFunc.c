#include "monty.h"

/**
 * get_opcodes - selects opcode fuction for right operation
 *
 * @opcode: opcode passed
 *
 * Return: pointer to the function
 */
void (*get_opcodes(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"queue", _queue},
		{"stack", _stack},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	int i = 0;

	while (instruct[i].opcode)
	{
		if (_strcmp(instruct[i].opcode, opcode) == 0)
			break;
		i++;
	}

	return (instruct[i].f);
}
