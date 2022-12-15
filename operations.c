#include "monty.h"
#include <stdlib.h>
#include <stdio.h>



void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *stk, *new;
	int i;

	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	i = atoi(ARGS[1]);
	if (i == 0 && ARGS[1][0] != '0')
	{
		free(new);
		free_stack(*stack);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new->n = i;
	stk = *stack;
	if (stk == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		new->next = stk;
		new->prev = NULL;
		*stack = new;
	}
}

void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *stk;

	stk = *stack;
	while(stk)
	{
		printf("%d\n", stk->n);
		stk = stk->next;
	}
}
