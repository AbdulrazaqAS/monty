#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

void (*get_func(char *opcode))(stack_t **stack, unsigned int line_num);

char **ARGS = NULL;

/**
 * main - Entry point
 * @argc: args count
 * @argv: args vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	FILE *filePtr;
	size_t bytes = 0;
	char *str = NULL, *token;
	int i, line_num;
	void (*func)(stack_t **stack, unsigned int line_num);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	ARGS = malloc(sizeof(char *) * 2);
	ARGS[0] = malloc(sizeof(char) * 20);
	ARGS[1] = malloc(sizeof(char) * 20);

	filePtr = fopen(argv[1], "r");
	if (filePtr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&str, &bytes, filePtr) != -1)
	{
		line_num = 1;
		for (i = 0; ; str = NULL, i++)
		{
			token = strtok(str, " \t\n$");
			if (token == NULL)
				break;

			strcpy(ARGS[i], token);
		}
		func = get_func(ARGS[0]);
		if (func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction <opcode>\n", line_num);
			exit(EXIT_FAILURE);
		}
		func(&stack, line_num);
		line_num++;
	}
	
	free(str);
	free(ARGS[0]);
	free(ARGS[1]);
	free_stack(stack);
	fclose(filePtr);
	exit(EXIT_SUCCESS);
}

void (*get_func(char *opcode))(stack_t **stack, unsigned int line_num)
{
	int i, a;

	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; funcs[i].opcode; i++)
	{
		if ((a = strcmp(opcode, funcs[i].opcode)) == 0)
			return (funcs[i].f);
	}

	return (NULL);
}

void free_stack(stack_t *stack)
{
	stack_t *tmp;

	tmp = stack;
	while(tmp)
	{
		free(tmp);
		tmp = tmp->next;
	}
}
