#include "header.h"

int *print_prompt(void)
{
	int i;
	char *prompt = "$ ";

	i = 0;
	while (prompt[i] != '\0')
	{
		print_char(prompt[i]);
		++i;
	}
	return (0);
}
