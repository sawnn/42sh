/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** Tools_SETUNS
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

void	print_list(s_list *list)
{
	s_list	*tmp = list;

	while (tmp) {
		my_printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
}

int	is_alpha(char *str)
{
	int	a = -1;

	while (str[++a])
		if ((str[a] < '0' || str[a] > '9')
		&& (str[a] < 'A' || str[a] > 'Z')
		&& (str[a] < 'a' || str[a] > 'z')) {
			my_puterror("setenv: Variable name must contain");
			my_puterror(" alphanumeric characters.\n");
			return (-1);
	}
	return (0);
}

int	check_first_c(char *str)
{
	int	a = -1;

	while (str[++a])
		if ((str[a] < 'A' || str[a] > 'Z')
		&& (str[a] < 'a' || str[a] > 'z')) {
			my_puterror("setenv : Variable name must begin ");
			my_puterror("with a letter.\n");
			return (-1);
		}
	return (0);
}

int	checks(use_value *use)
{
	if (is_alpha(use->arg[1]) == -1) return (-1);
	if (check_first_c(use->arg[1]) == -1) return (-1);
}
