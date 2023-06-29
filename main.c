#include "header.h"

int main(int __attribute__ ((unused)) argc, char *argv[], char **env)
{
	FILE *fp = 0;
	char *line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	char *cmd = NULL;
	int interactive;

	fp = stdin;

	interactive = _isinteractive();

	/* take control of environment */
	env = replicate_env(env);

	if (signal(SIGINT, interrupt_handler) == SIG_IGN)
	{
		signal(SIGINT, SIG_IGN);
	}

	while (1)
	{

		if (interactive)
		{
			print_prompt();
		}

		read = getline(&line, &len, fp);
		/* printf("Len: %lu\n", len); */
		/* printf("Address: %p\n", (void *) line); */

		if (fp == NULL)
		{
			/* if fp is a file which failed to open */
			perror(argv[0]);
			return (EXIT_FAILURE);
		}

		/* handle Ctrl+D */
		if (read == EOF)
		{
			_free(line);
			free_env(env);

			if (errno == 0)
			{
				return (EXIT_SUCCESS);
			}

			/* printf("errno is not 0.\n"); */
			perror(argv[0]);
			return (EXIT_FAILURE);
		}

		/* printf("Read: %d\n", (int) read); */
		/* print_buffer(line, read); */

		handle_comments(line);

		cmd = strtok(line, " \n");
		/* handles newline (empty command) + checks for built in */
		if (cmd != NULL && handle_builtins(cmd, line, &env))
		{
			canary("exec begins");

			/**
			 * PROGRAM EXEC
			 * fork() begins here
			 */

			if (handle_exec(cmd, line, &env))
			{
				canary("hello");
				free_env(env);
				perror(argv[0]);
				return (EXIT_FAILURE);
			}
		}
	}

	return (EXIT_SUCCESS);
}
