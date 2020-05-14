#include "monty.h"

/**
 * monty_interpret - takes the line from the file and executs the instruction.
 * @file: pointer to the monty file.
 *
 */

void monty_interpret(const char *monty_file)
{
	FILE *fp;
	char *line_ptr, **tokens;
	size_t size = 0;
	int bytes_read;
	unsigned int line_counter = 1;

	/** open monty_file and evaluate if is a valid file and get into fp*/
	fp = fopen(monty_file, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", monty_file);
                exit(EXIT_FAILURE);
	}
	else
	{
		/** get the lines in fp*/
		while (fp != '\0')
		{
			bytes_read = getline(&line_ptr, &size, fp);
			if (bytes_read < 0)
			{
				free(line_ptr);
				exit(EXIT_FAILURE);
			}
			/**set a counter for number of lines*/
			line_counter++;
			/**get the tokens of the line*/
			tokens = monty_tokenize(line_ptr);
			printf("%s\n", *tokens);
		}
	}
}
