#include "monty.h"

/**
 * monty_pint - A function that prints the top value of the stack.
 * @monty_stack: pointer to the stack.
 * @line_num: line number bytecode.
 */
void monty_pint(stack_t **monty_stack, unsigned int line_num)
{
	stack_t *tmp = *monty_stack;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can\'t print an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", tmp->n);
}


/**
 * monty_pop - A function that removes the top value in the stack.
 * @monty_stack: pointer to the stack.
 * @line_num: line number bytecode.
 */
void monty_pop(stack_t **monty_stack, unsigned int line_num)
{
	stack_t *tmp = *monty_stack;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can\'t pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (tmp->next)
		tmp->next->prev = tmp->prev;
	*monty_stack = tmp->next;
	free(tmp);
}

/**
 * monty_swap - A function that swaps the two values at the top of stack.
 * @monty_stack: The pointer to the top of a stack list.
 * @line_num: The line number of a Monty bytecodes file.
 */
void monty_swap(stack_t **monty_stack, unsigned int line_num)
{
	int tmp;

	if (*monty_stack == NULL || (*monty_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can\'t swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = (*monty_stack)->next->n;
	(*monty_stack)->next->n = (*monty_stack)->n;
	(*monty_stack)->n = tmp;
}

/**
 * monty_add - A function that adds the two top values of a stack.
 * @monty_stack: The pointer to the top of a stack list.
 * @line_num: The line number of a Monty bytecodes file.
 */
void monty_add(stack_t **monty_stack, unsigned int line_num)
{
	if ((*monty_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can\'t add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*monty_stack)->next->next->n += (*monty_stack)->next->n;
	monty_pop(monty_stack, line_num);
}

/**
 * monty_sub - A function that subtracts the second value from the top of a
 * stack linked by the top value.
 * @monty_stack: The pointer to the top of a stack list.
 * @line_num: The line number of a Monty bytecodes file.
 */
void monty_sub(stack_t **monty_stack, unsigned int line_num)
{
	if ((*monty_stack)->next == NULL || (*monty_stack)->next->next == NULL)
	{
		fprintf(stderr, "L%d: can\'t sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*monty_stack)->next->next->n -= (*monty_stack)->next->n;
	monty_pop(monty_stack, line_num);
}
