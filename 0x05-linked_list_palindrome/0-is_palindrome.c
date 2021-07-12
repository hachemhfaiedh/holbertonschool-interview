#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: singly linked list to be checked
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *i, *j;

	i = *head;
	j = *head;

	if (!i || !i->next)
		return (1);

	while (j->next)
		j = j->next;

	while (i < j)
	{
		if (i->n == j->n)
		{
			i = i->next;
			j -= 2;
		}
		else
			return (0);
	}
	return (1);
}