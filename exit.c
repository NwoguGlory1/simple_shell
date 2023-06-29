#include "header.h"

int valid_exitarg(char *arg, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		if (arg[i] < '0' || arg[i] > '9')
		{
			return (0);
		}
	}

	return (1);
}
