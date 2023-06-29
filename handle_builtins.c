#include "header.h"

/* returns 0 if user command is a built-in, 1 otherwise */
char handle_builtins(char *cmd, char *line __attribute__ ((unused)),
		     char ***env)
{
	/**
	 * BUILT-INS
	 */

	int exitn, arglen;
	char *arg = NULL;

	/* printf("%lu\n", read); */

	if (_strncmp(cmd, "exit", 5) == 0)
	{
		arg = strtok(NULL, " \n");
		if (arg != NULL)
		{
			arglen = _strlen(arg);
			if (valid_exitarg(arg, arglen) == 1)
			{
				exitn = _atoin(arg, arglen);
				free_env(*env);
				_free(line);
				exit(exitn);
			}
			print_string("exit: Illegal number\n");
			return (0);
		}
		_free(line);
		free_env(*env);
		exit(EXIT_SUCCESS);
	}

	if (_strncmp(cmd, "env", 4) == 0)
	{
		print_grid(*env);
		return (0);
	}

	if (_strncmp(cmd, "help", 5) == 0)
	{
		print_help();
		return (0);
	}

	if (_strncmp(cmd, "setenv", 7) == 0)
	{
		_setenv(env);
		return (0);
	}

	if (_strncmp(cmd, "unsetenv", 9) == 0)
	{
		_unsetenv(env);
		return (0);
	}

	return (1);
}
