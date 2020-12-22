0x19. C - Stacks, Queues - LIFO, FIFO

The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python).
It relies on a unique stack, with specific instructions to manipulate it.
The goal of this project is to create an interpreter for Monty ByteCodes files.
Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language.

0. Implement the push and pall opcodes.
push opcode: opcode push pushes an element to the stack.
pall opcode: opcode pall prints all the values on the stack, starting from the top of the stack.

1. pint: prints the value at the top of the stack, followed by a new line.
2. pop: opcode pop removes the top element of the stack.
3. swap: opcode swap swaps the top two elements of the stack.
4. add: opcode add adds the top two elements of the stack.
5. nop: opcode nop doesnt do anything.
