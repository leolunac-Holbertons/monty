#include "monty.h"

/**
* modop - divide top element from the second top element of the stack.
* @stack: pointer to the head node pointer of stack
* @line: the line number
* Return: Nothing.
*/
void modop(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
