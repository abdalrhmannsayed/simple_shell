#include "shell.h"

/**
 * env - displays the shell environment.
 *
 * @en: unused.
 *
 * Return: nothing
*/

void env(char *en __attribute__((unused)))
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		i++;
	}
}


/**
 * _getenv - function fetches requested enviroment variable
 *
 * @varname: the path for the enviroment variable needed
 *
 * Return: the path if successful or NULL if fail
 *
*/

char *_getenv(char *varname)
{
	size_t len = _strlen(varname), i = 0;

	if (varname == NULL || *varname == '\0')
	{
		return (NULL);
	}

	while (environ[i] != NULL)
	{
		if (_strncmp(varname, environ[i], len) == 0 && environ[i][len] == '=')
		{
			return (&environ[i][len + 1]);
		}
		i++;
	}

	return (NULL);
}
