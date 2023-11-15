#include "shell.h"

/**
 * tokenise - tokenises a string and puts them in an array
 * @buffer: contains the string to be tokenise
 * @arr: an array which contains the tokens
 * @delim: the delimeter
 *
 * Return: returns void
 */
void tokenise(char *buffer, char *arr[], char *delim)
{
	int j = 0;

	arr[j] = strtok(buffer, delim);

	while (arr[j] != NULL)
	{
		++j;
		arr[j] = strtok(NULL, delim);
	}
}
