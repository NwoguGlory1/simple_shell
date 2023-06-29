#include "header.h"

void canary(const char *s)
{
	static int i;

	if (DEBUG)
	{
		i++;
		printf("---%d---\n", i);
		puts(s);
		printf("-------\n");
	}
}

void print_buffer(void *ptr, size_t nmemb)
{
	unsigned long int i;
	char *tmp_ptr;

	tmp_ptr = ptr;

	print_horizontal_bar(nmemb);
	write(1, "\n", 1);

	write(1, "|", 1);
	for (i = 0; i < nmemb; i++)
	{
		write(1, " ", 1);
		if (*tmp_ptr == 10)
		{
			write(1, "\\n", 2);
		}
		else
		{
			write(1, tmp_ptr, 1);
		}
		write(1, " |", 3);
		tmp_ptr++;
	}

	write(1, "\n", 1);
	print_horizontal_bar(nmemb);

	tmp_ptr = ptr;

	write(1, "\n", 1);
	write(1, "|", 1);
	for (i = 0; i < nmemb; i++)
	{
		if (*tmp_ptr == 10)
		{
			printf("%3d |", *tmp_ptr);
			fflush(stdout);
		}
		else
		{
			printf("%3d|", *tmp_ptr);
			fflush(stdout);
		}
		tmp_ptr++;
	}

	write(1, "\n", 1);
	print_horizontal_bar(nmemb);
	write(1, "\n", 1);
}
