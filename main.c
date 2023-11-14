#include "shell.h"

/**
 * main - entry point
 *
 * Return: returns 0 or -1
 */
int main(int arc, char *env[])
{
	(void)arc;
	char *prompt = "££ ", *buffer = NULL, *delim = " \n", *parts, *new_buffer;
	char *arr[] = {NULL, NULL, NULL};
	int i = 0, j = 0, status, num_tok;
	size_t n;
	ssize_t num;
	pid_t child;

	
	while (1)
	{
		_print(prompt);

		num = getline(&buffer, &n, stdin);
		if (num == EOF)
		{
			_print("\n");
			exit(0);
		}
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				buffer[i] = 0;
			++i;
		}

		parts = strtok(buffer, delim);
		arr[j] = parts;
		parts = strtok(NULL, delim);
		arr[1] = parts;

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
