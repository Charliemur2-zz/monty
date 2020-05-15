#include "monty.h"

/**
 * main - interprets the commands in the lines of a file.
 * @ac: number of arguments in the prompt.
 * @av: pointer to arguments.
 * Return: ALways 0.
 */
int main(int ac, char **av)
{
	/**Conditional for limit to 2 arguments.*/
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	if (ac == 2)
	{
		monty_interpret(av[1]);
	}
	return (0);
}
