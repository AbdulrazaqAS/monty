#include "monty.h"


/**
 * _strdup - duplicates a string in memory
 * @s: string to duplicate
 *
 * Return: duplicate of @s
 */
char *_strdup(const char *s)
{
	size_t slen = strlen(s);
	char *result = malloc(slen + 1);

	if (!result)
		return (NULL);
	memcpy(result, s, slen + 1);
	return (result);
}

/**
 * is_number - determines if str is an integer
 * @str: string parameter
 *
 * Return: 1 (Success) or 0 (Fail)
 */
int is_number(const char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	while (str[i] != '\0')
	{
		if (isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/**
 * free_stack - frees up the memory occupied by the stack
 * @top: top of the stack
 *
 * Return: void
 */
void free_stack(stack_t *top)
{
	stack_t *curr;

	if (top != NULL)
	{
		while (top != NULL)
		{
			curr = top;
			top = top->prev;
			free(curr);
		}
	}
}

/**
 * stack_length - returns the length of a stack
 * @top: top of the stack
 *
 * Return: length of stack (integer)
 */
unsigned int stack_length(stack_t *top)
{
	stack_t *curr;
	unsigned int length = 0;


	curr = top;
	if (curr == NULL)
	{
		return (length);
	}
	else
	{
		while (curr != NULL)
		{
			curr = curr->prev;
			length++;
		}
	}
	return (length);
}
