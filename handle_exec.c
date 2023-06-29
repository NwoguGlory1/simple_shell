#include "header.h"

/* returns 0 on success, returns 1 if something went wrong */
char handle_exec(char *cmd, char *line, char ***env)
{
	/* char *null_ptr[] = { NULL }; */
	char *cargv[BUF_SIZE]; 		/* child argv */
	int i;
	char *full_exec_path = NULL;
	pid_t pid;
	int status;

	canary("handle exec begins");

	pid = fork();
	if (pid == -1)
	{
		return (1);
	}

	if (pid != 0)
	{
		/* we're in the parent process */
		canary("parent");

		/**
		 * wait() waits for a child to terminate. Upon child
		 * termination, wait() stores status information about
		 * the child on the int to which it points.
		 */
		wait(&status);

		/**
		 * ~WIFEXITED~ is a macro to inspect ~status~. It
		 * returns true if the child exited normally.
		 */
		if (WIFEXITED(status))
		{
			/* printf("Child terminated successfully.\n"); */
		}
	}
	else
	{
		/* we're in the child process */

		cargv[0] = cmd;

		for (i = 0; i < BUF_SIZE - 1; i++)
		{
			if (cargv[i] == NULL)
			{
				break;
			}

			cargv[i + 1] = strtok(NULL, " \n");
		}

		/* if relative path */
		if (cmd[0] == '.')
		{
			full_exec_path = cmd;
		}
		/* Get absolute path */
		else
		{
			full_exec_path = get_fpath(cmd, *env);

			if (full_exec_path == NULL)
			{
				/* memory error in ~get_fpath()~ */
				_free(line);
				return (1);
			}
		}

		/* Execute a program */
		if (execve(full_exec_path, cargv, *env) == -1)
		{
			canary("child execve");
			_free(line);
			return (1);
		}
	}

	/* execve(line, null_ptr, null_ptr); */
	return (0);
}
