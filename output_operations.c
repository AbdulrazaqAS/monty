#include "monty.h"

/**
 * print_all - prints all the elements on the stack
 * @top: top of the stack
 * @line_number: number of line of code in editor
 *
 * Return: void
 */
void print_all(stack_t **top, unsigned int line_number)
{
	stack_t *curr = *top;

	(void) line_number;
	if (curr != NULL)
	{
		while (curr != NULL)
		{
			fprintf(stdout, "%d\n", curr->n);
			curr = curr->prev;
		}
	}
}

/**
 * print_top - prints the contents at the top of the stack
 * @top: top of the stack
 * @line_number: number of line of code in the editor
 *
 * Return: void
 */
void print_top(stack_t **top, unsigned int line_number)
{
	if (*top != NULL)
	{
		fprintf(stdout, "%d\n", (*top)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(data.line), fclose(data.file);
		exit(EXIT_FAILURE);
	}
}

/**
 * print_char - prints the character stored at the top of the stack
 * @top: top of the stack
 * @line_number: number of current line of code in editor
 *
 * Return: void
 */
void print_char(stack_t **top, unsigned int line_number)
{
	int val;

	if (*top != NULL)
	{
		val = (*top)->n;
		if ((val >= 65 && val <= 90) || (val >= 97 && val <= 122))
		{
			fprintf(stdout, "%c\n", val);
		}
		else
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
			free(data.line), fclose(data.file);
			free_stack(*top);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free(data.line), fclose(data.file);
		exit(EXIT_FAILURE);
	}
}


/**
 * print_string - prints a string from all the characters on the stack
 * @top: top of the stack
 * @line_number: number of current code line in editor
 *
 * Return: void
 */
void print_string(stack_t **top, unsigned int line_number)
{
	stack_t *curr;

	(void) line_number;
	if (*top != NULL)
	{
		curr = *top;
		while (curr != NULL && curr->n != 0)
		{
			if ((curr->n >= 65 && curr->n <= 90) ||
					(curr->n >= 97 && curr->n <= 122))
			{
				printf("%c", curr->n);
			}
			else
				break;
			curr = curr->prev;
		}
	}
	printf("\n");
}
