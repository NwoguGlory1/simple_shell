#include "header.h"

void strip_newline(char *s, ssize_t read)
{
	if (s[read - 1] == '\n')
		s[read - 1] = '\0';
}
