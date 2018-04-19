/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** path
*/

#include "../include/my_minishell.h"

int	check_remove_path_bis(t_mini *mini, char *path3)
{
	if (access(path3, F_OK) == 0) {
		mini->rpath = path3;
		return (0);
	}
	if (access(mini->tab[0], F_OK) == 0) {
		mini->rpath = mini->tab[0];
		return (0);
	}
	return (-1);
}
