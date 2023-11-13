#include "shell.h"

/**
 * main - entry point
 *
 * Return: returns 0 or -1
 */
int main(void)
{
	char *prompt = "£ ", *buffer = NULL;
	size_t n;
	
	
	while (1)
	{
		_print(prompt);

		if (getline(&buffer, &n, stdin) == EOF)
		{
			perror("...... ");
			exit(0);
		}

		_print(buffer);
	
	}
	free(buffer);


	return (0);
}
