#include "monty.h"

/**
 * execute - Execute the corresponding function for the opcode
 * @opcode: Opcode to execute
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty ByteCode file
 */

void execute(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;
	int found = 0;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			found = 1;
			break;
		}
	}

	if (!found)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
