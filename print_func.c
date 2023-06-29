#include "header.h"

void print_string(char *s)
{
	while (*s != '\0')
	{
		print_char(*s);
		s++;
	}
}

void print_error(char *s)
{
	while (*s != '\0')
	{
		write(STDERR_FILENO, s, 1);
		s++;
	}
}

void print_horizontal_bar(unsigned long int n)
{
	unsigned long int i;

	for (i = 0; i < n * 5; i++)
	{
		write(1, "-", 1);
	}
}
