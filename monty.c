#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

stack_t *stack;

/**
 * main - Entry point
 * @argc: args count
 * @argv: args vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *filePtr;
	ssize_t chars;
	size_t bytes = 0;
	char *str = NULL, *token,*num, *tmp_str, *opcode;
	int i, line_num;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stack = malloc(sizeof(*stack));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	filePtr = fopen(argv[1], "r");
	if (filePtr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	while ((chars = getline(&str, &bytes, filePtr)) != -1)
	{
		line_num = 1;
		for (i = 0, tmp_str = str; i < 2; tmp_str = NULL, i++)
		{
			token = strtok(str, " \t$");
			if (token == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction <opcode>\n", line_num);
				exit(EXIT_FAILURE);
			}

			if (i == 0)
				opcode = token;
			else if (i == 1)
				num = token;
		}
		run_opcode(opcode, num, line_num);
	}

	free(str);
	fclose(filePtr);
	exit(EXIT_SUCCESS);
}

void run_opcode(char *opcode, char *num, int line)
{
	switch (opcode)
	{
		case "push":
			//To continue
	}
}
