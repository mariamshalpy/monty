#include "monty.h"

/**
 * print_char - Prints the Ascii
 * @stack: Pointer to a pointer pointing to top 
 * @line_number: Interger representing the line number 
 */


void print_char(stack_t **stack, unsigned int line_number)
{
	int as;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	as = (*stack)->n;
	if (as < 0 || as > 127)
		string_err(10, line_number);
	printf("%c\n", as);
}

/**
 * print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node 
 * @ln: Interger representing the line number 
 *
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int as;
	stack_t *t;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	t = *stack;
	while (t != NULL)
	{
		as = t->n;
		if (as <= 0 || as > 127)
			break;
		printf("%c", as);
		t = t->next;
	}

	printf("\n");
}

/**
 * rotl - Rotates the stack
 * @stack: Pointer to a pointer pointing to top 
 * @ln: Interger representing the line number
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	t = *stack;
	while (t->next != NULL)
		t = t->next;

	t->next = *stack;
	(*stack)->prev = t;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates in reverse
 * @stack: Pointer to a pointer pointing to top node
 * @ln: Interger representing the line numbe
 *
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	t = *stack;

	while (t->next != NULL)
		t = t->next;

	t->next = *stack;
	t->prev->next = NULL;
	t->prev = NULL;
	(*stack)->prev = t;
	(*stack) = t;
}
