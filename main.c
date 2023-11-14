#include "shell.h"

/**
 * main - entry point
 *
 * Return: returns 0 or -1
 */
int main(int arc, char *arv[] __attribute__((unused)), char *env[])
{
	char *prompt = "££ ", *buffer = NULL, *delim = " \n";
	char *arr[15];
	int i = 0, j = 0, status;
	size_t n;
	pid_t child;

	
	
	while (1)
	{
		_print(prompt);

		if (getline(&buffer, &n, stdin) == EOF)
		{
			_print("\n");
			exit(0);
		}
		
		arr[i] = strtok(buffer, delim);
		/*
		while (arr[i])
		{
			++i;
			arr[i] = strtok(NULL, delim);
		}
		*/

		child = fork();

		if (child == -1)
		{
			perror("forking faild\n");
			exit(0);
		}

		else if (child == 0)
		{
			if (execve(arr[0], arr, env) == -1)
			{
				_print("command not found\n");
				exit(0);
			}
		}

		else
		{
			wait(&status);
		}

	}
	free(buffer);

	return (0);
}
