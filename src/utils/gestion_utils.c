/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** path
*/

#include "../../include/my_sh.h"

int	is_bin(t_mini *mini)
{
	if (access(mini->tab[0], F_OK) == 0) {
		mini->rpath = mini->tab[0];
		return (0);
	}
	return (1);
}

void	color(t_mini *mini)
{
	int	i = 0;

	if (my_strcmp(mini->tab[0], "ls") == 0 && isatty(0) == 1) {
		while (mini->tab[i] != NULL) {
			i = i + 1;
		}
		mini->tab[i] = "--color";
		mini->tab[i + 1] = NULL;
	}
}

int	buff_null(t_mini *mini)
{
	if (isatty(0) == 1)
		write(1, "exit\n", 5);
	return (mini->global);
}

void	is_error_exit(t_mini *mini)
{
	mini->b_exit = 1;
	mini->global = 1;
}
