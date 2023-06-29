#include "header.h"

/**
 * handle_comments - strips the comment section of line
 */
void handle_comments(char *line)
{
		/* handle comments */
		strtok(line, "#");
}
