/*
** EPITECH PROJECT, 2018
** setenv
** File description:
** setenv
*/

#include "../include/my.h"
#include "../include/shell.h"
#include <stdlib.h>

void	print_list(t_env *list)
{
	t_env	*tmp = list;

	while (tmp) {
		my_printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
}

t_env	*add_link(t_env *list, char *str)
{
	t_env *tmp = list;
	t_env *new;

	while (tmp && tmp->next)
		tmp = tmp->next;
	if ((new = malloc(sizeof(t_env))) == NULL)
		return (NULL);
	new->str = str;
	new->next = NULL;
	if (!list)
		return (new);
	tmp->next = new;
	return (list);
}

void	is_alphanum(char *val, t_value *sh)
{
	int i = 0;

	while (val[i]) {
		if ((val[i] < 'A' || val[i] > 'Z') && (val[i] < 'a' ||
			val[i] > 'z') &&
			(val[i] < '0' || val[i] > '9')) {
			my_printf("setenv: Variable name must ");
			my_printf("contain alphanumeric characters.\n");
			sh->exit = 1;
			return;
		}
		i += 1;
	}
}

int	my_setenv(t_value *sh, char **arg)
{
	char *new;
	int i = 0;
	while (arg[i]) {
		is_alphanum(arg[i], sh);
		i += 1;
	}
	if (count_path(arg) > 3) {
		my_printf("setenv: Too many arguments.\n");
		sh->exit = 1;
	}
	else if (count_path(arg) == 1)
		print_list(sh->env);
	else {
		if (count_path(arg) == 2)
			new = my_strcat(arg[1], "=");
		else if (count_path(arg) == 3)
			new = my_strcat(arg[1], my_strcat("=", arg[2]));
		sh->env = add_link(sh->env, new);
	}
	return (0);
}
