#include "monty.h"

/**
 * _pall - prints the elements in stack.
 * @monty_stack: pointer to fist node,
 * @line_number: number of the line in the bytecode.
 *
 */
void _pall(stack_t **monty_stack, unsigned int line_number)
{
	stack_t *tmp = *monty_stack;
	(void)line_number;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
