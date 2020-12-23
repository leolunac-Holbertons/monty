#include "monty.h"
/**
* add - adds the top two elements together
* @stack: pointer to the head node pointer of stack
* @line: the line number
* Return: Nothing.
*/
void add(stack_t **stack, unsigned int line)
{
	/*printf("haciendo add:%d\n", line);*/
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
* nop - does nothing
* @stack: pointer to the head node pointer of stack
* @line: the line number
* Return: Nothing.
*/
void nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}
