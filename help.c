#include "header.h"

void print_help(void)
{
	print_string("SUPPORTED COMMANDS\n");

	print_string("#\t\t\t\tAdd a comment\n");
	print_string("env\t\t\t\tPrint the environment variables.\n");
	print_string("exit [n]\t\t\tExit the shell.\n");
	print_string("help\t\t\t\tDisplay this help.\n");
}
