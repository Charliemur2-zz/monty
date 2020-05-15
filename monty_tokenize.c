#include"monty.h"

/**
 * monty_tokenize - split the instruction and the value.
 * @line_to_token: line to be tokenized.
 * Return: doble pointer to tokens
 *
 */
char **monty_tokenize(char *line_to_token)
{
	char *first_token, **tokens;
	int i = 0;

	/** reserve space in memory for tokens*/
	tokens = malloc(sizeof(char *) * 64);
	/**validate the allocation*/
	if (tokens == NULL)
	{
		free(line_to_token);
		free(tokens);
		exit(EXIT_FAILURE);
	}
	/**create the first token*/
	first_token = strtok(line_to_token, " \n\t\r\a");
	/**validate the first token*/
	if (first_token == NULL)
	{
		free(line_to_token);
		free(tokens);
	}
	/**create the other tokens*/
	while (first_token != NULL)
	{
		tokens[i] = first_token;
		i++;
		first_token = strtok(NULL, " \n\t\r\a");
	}
	tokens[i] = '\0';
	return (tokens);
}
