#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp;
    unsigned int p = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    tmp = *head;

    /* Parcourt la liste jusqu'à l'index recherché */
    while (tmp != NULL && p < index)
    {
        tmp = tmp->next;
        p++;
    }

    /* L'index dépasse la taille de la liste */
    if (tmp == NULL)
        return (-1);

    /* Cas 1 : Suppression du premier nœud (index 0) */
    if (index == 0)
    {
        *head = tmp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    /* Cas 2 : Suppression au milieu ou à la fin */
    else
    {
        tmp->prev->next = tmp->next;
        if (tmp->next != NULL)
            tmp->next->prev = tmp->prev;
    }

    free(tmp);
    return (1);
}
