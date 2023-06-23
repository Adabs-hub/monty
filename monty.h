#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - headptr linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: headptr linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct data_s - structure use for global data management
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter
 * @head: headptr linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 */
typedef struct data_s
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} data_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern data_t param;

int dprintf(int fd, const char *format, ...);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/* opcode_instructuions*/
void _rotl(stack_t **headptr, unsigned int line_num);
void _stack(stack_t **headptr, unsigned int line_num);
void _add(stack_t **headptr, unsigned int line_num);

void _mul(stack_t **headptr, unsigned int line_num);
void _nop(stack_t **headptr, unsigned int line_num);
void _mod(stack_t **headptr, unsigned int line_num);
void _queue(stack_t **headptr, unsigned int line_num);

void _swap(stack_t **headptr, unsigned int line_num);
void _pint(stack_t **headptr, unsigned int line_num);
void _div(stack_t **headptr, unsigned int line_num);

void _pall(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _pop(stack_t **headptr, unsigned int line_num);
void _rotr(stack_t **headptr, unsigned int line_num);

void _sub(stack_t **headptr, unsigned int line_num);
void _pstr(stack_t **headptr, unsigned int line_num);
void _pchar(stack_t **headptr, unsigned int line_num);

/*get function*/
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/*imported functions*/
int _sch(char *s, char c);
char *_strtoken(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);

/* headptr linked list functions */
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* main */
void freeParam(void);

#endif
