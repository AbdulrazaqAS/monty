#include "monty.h"

/**
 * get_operations - selects which stack operation to perform programmatically
 * @command: string parameter
 *
 * Return: (*f)(stack_t **, unsigned int)
 */
void (*get_operations(const char *command))(stack_t **, unsigned int)
{
	instruction_t instrs[] = {
		{"push", push}, {"pall", print_all}, {"pint", print_top},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", no_operation}, {"sub", subtract}, {"div", divide},
		{"mul", multiply}, {"mod", modulus}, {"pchar", print_char},
		{"pstr", print_string}, {NULL, NULL}
	};
	int i = 0;

	while (instrs[i].opcode != NULL)
	{
		if (strcmp(command, instrs[i].opcode) == 0)
			return (instrs[i].f);
		i++;
	}
	return (NULL);
}
