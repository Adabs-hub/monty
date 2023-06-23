#include "monty.h"
#define  _GNU_SOURCE
#include <stdio.h>

/**
 * main - main program entery
 * @argc: number argsd
 * @argv: string vectors
 * Return: 0 on success, 1 otherwise
 */

data_t param;

int main(int argc, char **argv)
{
	char *read_line = NULL, *ch_value = NULL;
	int chread = 0;
	size_t buf_len = 128;

	initialize_param();

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	param.readfd = fopen(argv[1], "rb");

	if (param.readfd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	chread = getline(&read_line, &buf_len, param.readfd);
	while (chread != -1)
	{
		param.line_number++;
		param.opcode = strtok(read_line, " \t\n");
		trim_word(&param.opcode);
		ch_value = strtok(NULL, " \t\n");
		trim_word(&ch_value);
		toInt(ch_value);

		get_opcodeFunc(chread);


		chread = getline(&read_line, &buf_len, param.readfd);


	}

	freeParam();
	exit(EXIT_SUCCESS);
	return (0);
}

/**
 * trim_word - trim leading and trailing spaces
 * @str: input string
 * Return: new string;
 */
char *trim_word(char **str)
{
	int  i,j;
	char *s = NULL;

	if (str == NULL || *str == NULL)
		return (NULL);
	s = *str;
	for(i=0; s[i] == ' ' || s[i] == '\t'; i++);

	for(j=0;s[i];i++)
	{
		s[j++]=s[i];
	}
	s[j]='\0';
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]!=' '&& s[i]!='\t')
				j=i;
	}
	s[j+1]='\0';

	return (s);
}

/**
 * isInt - check is string is an int
 * @str: string arg
 * Return: 0 if an INT 1 if otherwise
 */
void toInt(char *str)
{
	int str_len = 0, j = 0;

	if (strcmp(param.opcode, "push") == 0)
	{
		if (str != NULL)
		{
			str_len = strlen(str);
			while (j < str_len)
			{
				if (str[j] > 47 && str[j] < 58)
					j++;
				else
					break;

				j++;
			}
		}
		else
			if (j != str_len)
			{
				fprintf(stderr, "L%u: usage: push integer\n", param.line_number);
				exit(EXIT_FAILURE);
			}

		param.value = atoi(str);
	}
}

