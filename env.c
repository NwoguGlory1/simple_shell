#include "header.h"

char **replicate_env(char **env)
{
	int i;
	int env_len;
	char **tmp_env;

	i = 0;
	while (env[i] != NULL)
	{
		i++;
	}
	env_len = i;

	tmp_env = malloc(sizeof(char *) * (env_len + 1));

	for (i = 0; i < env_len; i++)
	{
		tmp_env[i] = _strdup(env[i]);
		if (tmp_env[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
	}

	tmp_env[i] = NULL;

	return (tmp_env);
}

void free_env(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		free(env[i]);
	}

	free(env);
}
