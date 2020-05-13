#include "monty.h"

/**
 * main - interprets the commands in the lines of a file.
 * @ac: number of arguments in the prompt.
 * @av: pointer to arguments.
 */
void main(int ac, char **av)
{
	/** take the arguments of the prompt. First is monty programm always and
	    second is the file.
	*/
	/** conditional for limit to 2 arguments.*/
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
}
