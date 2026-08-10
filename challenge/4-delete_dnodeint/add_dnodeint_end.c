#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Add a node at the end of a list
 *
 * @head: The address of the pointer to the first element of the list
 * @n: The number to store in the new element
 *
 * Return: A pointer to the new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *l;

	/* Vérification que le pointeur d'adresse n'est pas NULL */
	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	new->next = NULL;

	/* Cas 1 : La liste est actuellement vide */
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	/* Cas 2 : Parcours jusqu'au dernier élément */
	l = *head;
	while (l->next != NULL)
	{
		l = l->next;
	}

	l->next = new;
	new->prev = l;

	return (new);
}
