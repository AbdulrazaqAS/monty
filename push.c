#include <stdlib.h>
#include <stdio.h>

stack_t *stack;

int main(int argc, char *argv[])
{
	if argc != 2 || (atoi(argv[1]) == 0 && argv[1][0] != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", __LINE__);
		exit(EXIT_FAILURE);
	}

	stack = malloc(sizeof(*stack));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}


