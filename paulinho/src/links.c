/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** List
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

s_list	*rm_link(s_list *list, char *str)
{
	s_list	*tmp = list;

	while (tmp->next) {
		if (my_strncmp(str, tmp->next->str, my_strlen(str)) == 0)
			tmp->next = tmp->next->next;
		else
			tmp = tmp->next;
	}
	return (list);
}

s_list	*add_link(s_list *list, char *str)
{
	s_list	*elem = malloc(sizeof(s_list));

	elem->next = NULL;
	elem->str = str;
	if (!list)
		return (elem);
	s_list	*tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	return (list);
}

s_list	*get_env(char **zer, s_list *list)
{
	int	a = -1;

	while (zer[++a])
		list = add_link(list, zer[a]);
	return (list);
}
