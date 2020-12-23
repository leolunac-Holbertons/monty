#include "monty.h"
/**
* processfile - Read file line by line
* @file: file to read
* Description:  no return
*/
void processfile(FILE *file)
{

unsigned int line_number = 0;
char *line = NULL;
char *opcode = NULL;
char *arg = NULL;
size_t size = 0;
stack_t *stack = NULL;

	while (getline(&line, &size, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n");
		/*printf("opcode antes de:%s\n", opcode);*/
		if (opcode == NULL || strchr(opcode, '#') != NULL)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			/*printf("opcode push:%s\n", opcode);*/
			arg = strtok(NULL, " \n");
			if (arg != NULL && valid_arg(arg))
			{
				push(&stack, line_number, arg);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(opcode);
				free_stack(&stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/*printf("opcode difpush:%s\n", opcode);*/
			get_opcode_func(opcode, &stack, line_number, file);
		}
	}
	free(opcode);
	free_stack(&stack);
}

/**
* get_opcode_func - process each command
* @opcode: code to execute
* @stack: structure to use
* @line: number of line
* @f: file
* Description:  return 1 if is, 0 if not
* Return: int
*/
void get_opcode_func(char *opcode, stack_t **stack, unsigned int line, FILE *f)
{
	int i = 0;
	instruction_t opcodes[] = {{"pall", pall},
				   {"pint", pint}, {"pop", pop},
				   {"swap", swap}, {"add", add},
				   {"nop", nop}, {"sub", subop},
				   {"mul", mulop}, {"div", divop},
				   {"mod", modop}, {NULL, NULL}};

/*(void)stack;*/
/*(void)line;*/
/*(void)opcode;*/
/*printf("opcode parametro:%s, linea:%d\n", opcode,line);*/

	for ( ; i < 10; i++)
	{
		/*printf("opcode del struct:%s\n",opcodes[i].opcode);*/
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(stack, line);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
	free(opcode);
	free_stack(stack);
	fclose(f);
	exit(EXIT_FAILURE);
}

/**
* valid_arg - valid push arguments
* @arg: push argument
* Description:  return 1 if is, 0 if not
* Return: bool
*/
bool valid_arg(char *arg)
{
	int i = 0;

	for ( ; arg[i]; i++)
	{
		if (arg[0] == '-')
			continue;

		if (isdigit(arg[i]) == 0)
			return (false);
	}
	return (true);
}

/**
 * free_stack - frees a list.
 * @head: head of list
 * Description: free list
 * Return: Nothing
 */
void free_stack(stack_t **head)
{

	stack_t *temp = NULL;

	if (head == NULL || *head == NULL)
		return;

	while (*head != NULL)
	{
		temp = (*head)->next;
		free(*head);
		(*head) = temp;
	}
}
