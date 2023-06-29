#include "header.h"

void interrupt_handler(int signum __attribute__((unused)))
{
	print_string("\n");
	print_prompt();
}
