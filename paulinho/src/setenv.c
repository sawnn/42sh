/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** Setenv
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

int	setenv_1(use_value *use, s_list *list)
{
	char	*trans = malloc(sizeof(char) * my_strlen(use->arg[1]) + 2);
	s_list	*tmp = list;

	trans = my_strcat(use->arg[1], "=");
	if (checks(use) == -1) {
		use->exit = 1;
		return (-1);
	}
	while (tmp) {
		if (my_strncmp(use->arg[1], tmp->str,
			my_strlen(use->arg[1])) == 0) {
			tmp->str = trans;
			return (0);
		}
		tmp = tmp->next;
	}
	add_link(list, trans);
	return (0);
}

int	setenv_2(use_value *use, s_list *list)
{
	char	*trans = malloc(sizeof(char) * my_strlen(use->arg[1]) + 2);
	char	*tranzer = malloc(sizeof(char) * my_strlen(use->arg[2]) + 2);
	s_list	*tmp = list;

	trans = my_strcat(use->arg[1], "=");
	tranzer = my_strcat(trans, use->arg[2]);
	if (checks(use) == -1) {
		use->exit = 1;
		return (-1);
	}
	while (tmp) {
		if (my_strncmp(use->arg[1], tmp->str,
			my_strlen(use->arg[1])) == 0) {
			tmp->str = tranzer;
			return (0);
		}
		tmp = tmp->next;
	}
	add_link(list, tranzer);
	return (0);
}

int	setenv_func(use_value *use, char **env, s_list *list)
{
	int	size = size_tab(use->arg);

	size == 1 ? print_list(list) : 0;
	if (size == 2)
		if (setenv_1(use, list) == -1) {
			use->exit = 1;
			return (1);
		}
	if (size == 3)
		if (setenv_2(use, list) == -1) {
			use->exit = 1;
			return (1);
		}
	if (size >= 4) {
		my_puterror("setenv: Too many arguments.\n");
		use->exit = 1;
		return (1);
	}
	return (0);
}
