/*
** EPITECH PROJECT, 2017
** linked list
** File description:
** gaspacho andalou
*/

#include "my.h"

t_list	*add_node(t_list *list, char *str)
{
	t_list	*tmp = NULL;

	if ((tmp = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	tmp->str = my_strdup(str);
	tmp->next = list;
	list = tmp;
	return (tmp);
}
