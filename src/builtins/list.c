/*
** EPITECH PROJECT, 2018
** list
** File description:
** .c
*/

#include "../../include/shell.h"

t_set	*addd_link(t_set *list, char *op, char *value)
{
	t_set *tmp = list;
	t_set *new = NULL;

	while (tmp && tmp->next)
		tmp = tmp->next;
	if ((new = malloc(sizeof(t_set))) == NULL)
		return (NULL);
	new->op = op;
	new->value = value;
	new->next = NULL;
	if (!list)
		return (new);
	tmp->next = new;
	return (list);
}
