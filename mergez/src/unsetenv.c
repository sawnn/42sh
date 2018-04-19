/*
** EPITECH PROJECT, 2018
** unsetenv
** File description:
** unsetenv
*/

#include "../include/my.h"
#include "../include/shell.h"

int	strlen_equal(char *val)
{
	int i = 0;

	while (val[i] != '=')
		i = i + 1;
	return (i);
}

t_env	*check_env(t_env *list, char *val, t_value *sh)
{
	t_env *tmp = list;

	if (tmp->next == NULL && my_strncmp(tmp->str,
						val, strlen_equal(val)) == 0) {
		tmp->next = tmp->next->next;
		return (list);
	}
	while (tmp->next) {
		if (my_strncmp(tmp->next->str,
				val, strlen_equal(tmp->next->str)) == 0) {
			tmp->next = tmp->next->next;
			return (list);
		}
		tmp = tmp->next;
	}
	return (list);
}

int	my_unsetenv(t_value *sh, char **arg)
{
	int i = -1;

	while (arg[++i]) {
		if (count_path(arg) == 1) {
			my_printf("unsetenv: Too few arguments.\n");
			sh->exit = 1;
		}
		sh->env = check_env(sh->env, arg[i], sh);
	}
	return (0);
}
