#include "shell.h"
/**
 * main - entry point to my shell
 * @ac: this is the argument count
 * @argv: an array containing the arguments passed to main
 * @env: this is the environment
 * Return: returns 0 or -1
 */
int main(int ac __attribute__((unused)), char *argv[], char *env[])
{
	char *prompt = "££ ", *buffer = NULL;
	int status;
	char *arr[2];
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
		arr[0] = buffer;
		arr[1] = NULL;
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
				_print(argv[0]);
				_print(": No such file or directory\n");
				exit(0);
			}
		}
		else
			wait(&status);
	}
	free(buffer);
	return (0);
}
