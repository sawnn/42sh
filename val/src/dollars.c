/*
** EPITECH PROJECT, 2018
** dollard
** File description:
** .c
*/

#include "../include/shell.h"

char	*dollars(char *str, t_node *list)
{
	t_node *tmp = list;

	while (tmp) {
		if (strcmp(tmp->op, str) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	printf("%s: Undefined variable.\n", str);
	return (NULL);
}