/*
** EPITECH PROJECT, 2018
** env
** File description:
** gaspacho andalou
*/

#include "my.h"

void	print_env(UNU char *input, t_list **my_env)
{
	t_list	*tmp = *my_env;

	while (tmp->next) {
		my_printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
}

void	my_setenv(char *input, t_list **my_env)
{
	char	**tab = my_str_to_wordtab(input, ' ');
	t_list	*tmp = *my_env;
	t_list	*save = *my_env;

	if (!tab[1]) {
		print_env(input, my_env);
		return;
	}
	my_strcmp(tab[1], "PATH") == 0 ? keep_path(2) : 0;
	if (check_name(tab) == 1)
		return;
	while (tmp->next) {
		if (my_strncmp(tab[1], tmp->str, my_strlen(tab[1])) == 0) {
			setenv_exist(tab, tmp, my_env, save);
			return;
		}
		tmp = tmp->next;
	}
	setenv_new_node(tab, &tmp, my_env, save);
}

int	check_tab(char **tab)
{
	if (!tab[1]) {
		my_printf("%s: Too few arguments.\n", tab[0]);
		return (1);
	}
	my_strcmp(tab[1], "PATH") == 0 ? keep_path(1) : 0;
	return (0);
}

void	my_unsetenv(char *input, t_list **my_env)
{
	t_list	*tmp = *my_env;
	t_list	*save = *my_env;
	char	**tab = my_str_to_wordtab(input, ' ');

	if (check_tab(tab) == 1)
		return;
	if (my_strncmp(tab[1], tmp->str, my_strlen(tab[1])) == 0) {
		*my_env = (*my_env)->next;
		return;
	}
	while (tmp->next) {
		if (my_strncmp(tab[1],
			tmp->next->str, my_strlen(tab[1])) == 0) {
			*my_env = tmp;
			(*my_env)->next = (*my_env)->next->next;
			*my_env = save;
			return;
		}
		tmp = tmp->next;
	}
}

void	my_exit(char *str, UNU t_list **env)
{
	char	**tab = my_str_to_wordtab(str, ' ');

	if (tab[1] == NULL)
		exit(0);
	else if (my_getnbr(tab[1]) == 85 || count_tabs(tab) > 2) {
		my_putstr("exit: Expression Syntax.\n");
		return;
	}
	exit(my_getnbr(tab[1]));
}
