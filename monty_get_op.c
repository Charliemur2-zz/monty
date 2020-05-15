#include "monty.h"

/**
 * monty_get_op - search the correct instruccion to exec.
 * @token: string to compare with the instructions.
 * @monty_stack: stack.
 * @line_num: number of line.
 */
void monty_get_op(char **token, stack_t **monty_stack, unsigned int line_num)
{
	unsigned int i, j;
	char *str = "usage: push integer";
	instruction_t op[] = {{"push", _push}, {"pall", _pall}, {"pint", _pint},
			      {"pop", _pop}, {"swap", _swap}, {"add", _add}, {"sub", _sub},
			      {"null", NULL}};

	for (i = 0; i <= 7; i++)
	{
		if (strcmp(op[i].opcode, token[0]) == 0)
		{
			if (strcmp(op[i].opcode, "push") == 0)
			{
				if (token[1] == NULL)
				{
					fprintf(stderr, "L%d: %s\n", line_num, str);
					exit(EXIT_FAILURE);
				}
				for (j = 0; token[1][j]; j++)
				{
					if (token[1][j] == '-' && j == 0)
						continue;
					if (token[1][j] < '0' || token[1][i] > '9')
					{
						free_stack(monty_stack);
						free(token);
						fprintf(stderr, "L%d: %s\n", line_num, str);
						exit(EXIT_FAILURE);
					}
				}
				line_num = atoi(token[1]);
			}
			op[i].f(monty_stack, line_num);
			free(token);
			return;
		}
	}
	free_stack(monty_stack);
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, token[0]);
	free(token);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - frees the list.
 * @head: pointer to first node.
 */

void free_stack(stack_t **head)
{
	stack_t *tmp = *head;

	while ((*head) != NULL)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}
