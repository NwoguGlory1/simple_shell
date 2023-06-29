#include "header.h"

int _unsetenv(char ***env)
{
	int i;

	/* declarations */
	char *envvar, *dup;

	envvar = strtok(NULL, " \n");
	if (envvar == NULL)
	{
		print_error("missing argument\n");
		return (1);
	}

	for (i = 0; (*env)[i] != NULL; i++)
	{
		dup = strtok(strdup((*env)[i]), "=");
		if (_strcmp(dup, envvar) == 0)
		{
			/* env var found */
			free(dup);
			printf("found: %s\n", (*env)[i]);
			shrink_env(env, i);
			return (0);
		}
		free(dup);
	}

	printf("not found\n");
	printf("query: %s\n", envvar);
	return (0);
}

void shrink_env(char ***env, int del)
{
	int i, env_size;
	char **new_env;

	for (i = 0; (*env)[i] != NULL; i++)
	{
	}

	env_size = i;

	if (DEBUG == 1)
		printf("env size: %d\n", i);

	/* env_size without +1 since we are shrinking */
	new_env = malloc(sizeof(char *) * (env_size));

	/* copy up to `del` */
	for (i = 0; i < del; i++)
	{
		new_env[i] = _strdup((*env)[i]);

		if (new_env[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
	}

	/* copy the remaining values */
	for (i = del; (*env)[i] != NULL; i++)
	{
		if ( (*env)[i + 1] != NULL )
			new_env[i] = _strdup((*env)[i + 1]);
		else
			new_env[i] = NULL;
	}

	free_env(*env);
	*env = new_env;
}
