#include "monty.h"

/**
 * push - pushes a node to the top of the stack
 * @top: top of the stack
 * @line_number: current line in the editor where the code was typed in
 *
 * Return: void
 */
void push(stack_t **top, unsigned int line_number)
{
	stack_t *new_node;
	int push_data;

	if (is_number(data.operand) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(data.line), fclose(data.file);
		exit(EXIT_FAILURE);
	}
	push_data = atoi(data.operand);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(data.line), fclose(data.file);
		exit(EXIT_FAILURE);
	}
	new_node->n = push_data;
	if (*top == NULL)
	{
		*top = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		(*top)->next = new_node;
		new_node->next = NULL;
		new_node->prev = *top;
		*top = new_node;
	}
}


/**
 * pop - removes the top of the stack
 * @top: top of the stack
 * @line_number: number of line of code in editor
 *
 * Return: void
 */
void pop(stack_t **top, unsigned int line_number)
{
	stack_t *popped;

	if (*top != NULL)
	{
		popped = *top;
		if ((*top)->prev != NULL)
		{
			*top = (*top)->prev;
			(*top)->next = NULL;
			free(popped);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(data.line), fclose(data.file);
		exit(EXIT_FAILURE);
	}
}


/**
 * swap - swaps the top two elements of the stack
 * @top: top of the stack
 * @line_number: editor's line number
 *
 * Return: void
 */
void swap(stack_t **top, unsigned int line_number)
{
	stack_t *popped;
	unsigned int length;

	length = stack_length(*top);
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(data.line), fclose(data.file);
		exit(EXIT_FAILURE);
	}
	else if (length < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(data.line), fclose(data.file);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	else
	{
		popped = *top;
		*top = (*top)->prev;
		(*top)->next = NULL;
		popped->prev = (*top)->prev;
		(*top)->prev = popped;
		popped->next = *top;
	}
}
