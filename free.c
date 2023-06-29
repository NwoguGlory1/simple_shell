#include "header.h"

void _free(char *line)
{
	free(line);
}

/* see ~memset(3)~ */
void _memset(void *s, int c, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		*((char *) s + i) = c;
	}
}
