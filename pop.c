#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	if (current->next != NULL)
	{
		current->next->prev = current->prev;
		*stack = current->next;
	}
	else
	{
		*stack = NULL;
	} 
	free(current);
}
