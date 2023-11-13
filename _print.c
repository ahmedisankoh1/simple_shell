#include "shell.h"

/**
 * _print - prints a string
 * @string: string to be printed
 * Return: returns the string
 */
int _print(char *string)
{
	int char_to_print = 0, i = 0;

	while (string[i])
	{
		char_to_print = char_to_print + _putchar(string[i]);
		i++;
	}
	return (char_to_print);
}
