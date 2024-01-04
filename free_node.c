#include "monty.h"

/**
 * free_node - frees a node from the stack if push is called
 * @stack: pointer to the top of the stack
 * Return: void
 */

void free_node(stack_t **stack)
{
	stack_t *new_node;

	new_node = *stack;

	while (new_node)
	{
		*stack = new_node->next;
		free(new_node);
		new_node = *stack;
	}
}
