/*
** EPITECH PROJECT, 2018
** list
** File description:
** .c
*/

#include "../include/shell.h"

void	print_list(t_node *list)
{
	t_node	*tmp = list;

	while (tmp) {
		printf("%s = %s\n", tmp->op, tmp->value);
		tmp = tmp->next;
	}
}

t_node	*add_link(t_node *list, char *op, char *value)
{
	t_node *tmp = list;
	t_node *new = NULL;

	while (tmp && tmp->next)
		tmp = tmp->next;
	if ((new = malloc(sizeof(t_node))) == NULL)
		return (NULL);
	new->op = op;
	new->value = value;
	new->next = NULL;
	if (!list)
		return (new);
	tmp->next = new;
	return (list);
}
