#include "monty.h"

data_t data = {NULL, NULL, NULL};

/**
 * main - main entry point of the program
 * @argc: count of command line arguments
 * @argv: vector of command line arguments
 *
 * Return: 0 (Success) or errno (Fail)
 */
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		handle_program(argv[1]);
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * handle_program - handles the execution of the program
 * @file_name: name of code file to run
 *
 * Return: void
 */
void handle_program(char *file_name)
{
	size_t line_number = 1, length = 0;
	char *command = NULL;
	stack_t *prog_stack = NULL;
	void (*operation)(stack_t **, unsigned int);

	data.file = fopen(file_name, "r");
	if (data.file)
	{
		while (getline(&data.line, &length, data.file) != -1)
		{
			data.line[strcspn(data.line, "\n")] = '\0';
			command = strtok(data.line, " ");
			if (command == NULL)
				continue;
			if (strcmp(command, "#") == 0)
				continue;
			data.operand = strtok(NULL, " ");
			operation = get_operations(command);
			if (!operation)
			{
				fprintf(stderr, "L%lu: unknown instruction %s\n", line_number, command);
				free(data.line), fclose(data.file), exit(EXIT_FAILURE);
			}
			operation(&prog_stack, line_number);
			line_number++;
		}
		free(data.line), free_stack(prog_stack), fclose(data.file);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
}
