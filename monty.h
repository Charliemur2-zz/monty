#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	nt n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

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

void monty_interpret(const char *monty_file);
char **monty_tokenize(char *line_to_token);
int is_empty_line(char *line, char *delims);
void monty_get_op(char **token, stack_t **monty_stack, unsigned int line_num);
void _push(stack_t **head, unsigned int value);
void _pall(stack_t **monty_stack, unsigned int line_number);
void _pint(stack_t **monty_stack, unsigned int line_num);
void _pop(stack_t **monty_stack, unsigned int line_num);
void _swap(stack_t **stack, unsigned int line_number);
void _sub(stack_t **monty_stack, unsigned int line_num);
void free_stack(stack_t **head);
void _add(stack_t **monty_stack, unsigned int line_num);
#endif /* _MONTY_H_ */
