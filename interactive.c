#include "header.h"

/* returns 1 if interactive, 0 if pipe */
int _isinteractive(void)
{
	struct stat st;

	if (fstat(0, &st) == -1)
	{
		perror("fstat");
		exit(EXIT_FAILURE);
	}

	if (S_ISFIFO(st.st_mode))
	{
		canary("pipe");
		return (0);
	}

	canary("not pipe");
	return (1);
}
