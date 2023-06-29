#include "header.h"

/**
 * _setenv - set an environment variable
 *
 * @env: the current environment
 *
 * Return: 0 on success, 1 otherwise.
 */
int _setenv(char ***env)
{
	/* declarations */
	char *envvar, *envval;

	envvar = strtok(NULL, " \n");
	if (envvar == NULL)
	{
		print_error("missing argument\n");
		return (1);
	}

	envval = strtok(NULL, " \n");
	if (envval == NULL)
	{
		print_error("missing value\n");
		return (1);
	}

	return (_setenv_func(env, envvar, envval));
}

/**
 * _setenv_func - helper to _setenv
 *
 * @env: the current environment
 * @envvar: variable name
 * @envval: variable value
 *
 * Return: 0 on success, 1 otherwise.
 */
int _setenv_func(char ***env, char *envvar, char *envval)
{
	/* declarations */
	char **new_env;
	int i;

	for (i = 0; (*env)[i] != NULL; i++)
	{
		/* variable exists */
		if (_cstrcmp((*env)[i], envvar) == 0)
		{
			free((*env)[i]);
			(*env)[i] = new_path_str(envvar, envval);
			return (0);
		}
	}

	if (DEBUG == 1)
		printf("old env size: %d\n", i);

	/* variable does not exist */
	new_env = grow_env(*env, i);
	if (env == NULL)
	{
		perror("grow_env");
		return (1);
	}

	free(*env);

	*env = new_env;

	(*env)[i] = new_path_str(envvar, envval);
	printf("%s\n", (*env)[i]);

	(*env)[++i] = NULL;

	if (DEBUG == 1)
		printf("new env size: %d\n", i);

	return (0);
}

/**
 * grow_env - grow env by one, copy all the present key-value pairs
 *
 * @env: the current environment
 * @env_size: the size of the current environment, not including NULL
 * terminating pointer.
 *
 * Return: the new environment, NULL on memory error.
 */
char **grow_env(char **env, int env_size)
{
	int i;
	char **new_env;

	/* grow environment by one + NULL pointer */
	new_env = malloc(sizeof(char **) * (env_size + 2));
	if (new_env == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	/* copy all the pointers to strings to new environment */
	for (i = 0; i < env_size; i++)
	{
		new_env[i] = env[i];
	}

	/* return new environment */
	return (new_env);
}
