#include "monty.h"

/**
 * err - Prints appropiate error messages 
 * @error_code: The error codes 
 */




void err(int error_code, ...)
{
	va_list a;
	char *o;
	int l_num;

	va_start(a, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(a, char *));
			break;
		case 3:
			l_num = va_arg(a, int);
			o = va_arg(a, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, o);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(a, int));
			break;
		default:
			break;
	}

	free_nodes();

	exit(EXIT_FAILURE);
}

/**
 * more_err - handles errors.
 * @error_code: The error codes are the following:
 */



void more_err(int error_code, ...)
{
	va_list a;
	char *o;
	int l_num;

	va_start(a, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(a, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(a, int));
			break;
		case 8:
			l_num = va_arg(a, unsigned int);
			o = va_arg(a, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, o);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(a, unsigned int));
			break;
		default:
			break;
	}

	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors.
 * @error_code: The error codes are the following:
 */


void string_err(int error_code, ...)
{
	va_list a;
	int l_num;

	va_start(a, error_code);
	l_num = va_arg(a, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

