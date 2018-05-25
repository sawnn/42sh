/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** Unsetenv
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

int	unsetenv_func(use_value *use, char **env, s_list *list)
{
	int	a = 0;
	int	size = size_tab(use->arg);

	if (size == 1) {
		use->exit = 1;
		my_puterror("unsetenv : Too few arguments.\n");
			return (-1);
	}
	while (use->arg[++a])
		rm_link(list, use->arg[a]);
	return (0);
}
