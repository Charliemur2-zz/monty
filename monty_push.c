#include "monty.h"

/**
 * _push - pushes an element to the stack.
 * @value: value to push on the stack.
 * @head: pointer to first node.
 */
void _push(stack_t **head, unsigned int value)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		exit(EXIT_FAILURE);
	newnode->n = value;
	newnode->next = *head;
	if (*head != NULL)
		newnode->next->prev = newnode;
	newnode->prev = NULL;
	*head = newnode;
}
