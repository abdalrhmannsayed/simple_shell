#include "shell.h"

/**
  * _puts2 - function prints strings and prints a new line aftre
  *
  * @c: pointer to strings of character
  *
  * Return: Void
*/

void _puts2(char *c)
{
	write(STDOUT_FILENO, c, _strlen(c));
}

/**
  * print_error - Display Error Based on Command and How Many Time Shell Looped
  *
  * @input:User Input
  *
  * @counter:Simple Shell Count Loop
  *
  * @argv:Program Name
  *
  * Return: Void
  */

void print_error(char *input, int counter, char *argv)
{
	char *er;

	_puts2(argv);
	_puts2(": ");
	er = _itoa(counter);
	_puts2(er);
	free(er);
	_puts2(": ");
	_puts2(input);
	_puts2(": not found\n");
}
