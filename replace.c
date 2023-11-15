#include "shell.h"
/**
 * rm_newline - searche for a new line character and replaces it
 * @string: string to be edited
 * Return: returns void
 */
void rm_newline(char *string)
{
	int i = 0;

	while (string[i])
	{
		if (string[i] == '\n')
			string[i] = 0;
		++i;
	}
}
