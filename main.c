#include "shell.h"
/**
 * main - entry point to my shell
 * @ac: this is the argument count
 * @env: this is the environment
 * Return: returns 0 or -1
 */
int main(int ac __attribute__((unused)), char *env[])
{
	char *prompt = "££ ", *buffer = NULL, *delim = " \n";
	int status;
	char *arr[15];
	size_t n;
	pid_t child;

	while (1)
	{
		if (isatty(0))
			_print(prompt);
		if (getline(&buffer, &n, stdin) == EOF)
		{
			_print("\n");
			exit(0);
		}
		rm_newline(buffer);
		tokenise(buffer, arr, delim);
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
			wait(&status);
	}
	free(buffer);
	return (0);
}
