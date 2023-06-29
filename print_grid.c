#include "header.h"

void print_grid(char **grid)
{
	int i;

	for (i = 0; grid[i] != NULL; i++)
	{
		print_string(grid[i]);
		print_char('\n');
	}
}
