#include "monty.h"

/**
 * monty_interpret - takes the line from the file and executs the instruction.
 * @monty_file: pointer to the monty file.
 *
 */

void monty_interpret(const char *monty_file)
{
	FILE *fp = NULL;
	char *line_ptr = NULL, **tokens = NULL, *limiters = " \n\b\t\a";
	size_t size = 0;
	int bytes_read = 0;
	unsigned int line_counter = 0;
	stack_t *monty_stack = NULL;

	fp = fopen(monty_file, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", monty_file);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (fp != '\0')
		{
			bytes_read = getline(&line_ptr, &size, fp);
			if (bytes_read < 0)
			{
				free(line_ptr);
				exit(EXIT_FAILURE);
			}
			line_counter++;
			if (is_empty_line(line_ptr, limiters))
				continue;
			tokens = monty_tokenize(line_ptr);
			monty_get_op(tokens, &monty_stack, line_counter);
		}
		free(line_ptr);
	}
}

/**
 * is_empty_line - A function that checks if line only contains delimiters.
 * @line: The pointer to the line.
 * @delims: The string with delimiter characters.
 * Return: 1 if the line only contains delimiters, otherwise 0.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}
	return (1);
}
