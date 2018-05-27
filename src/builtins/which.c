/*
** EPITECH PROJECT, 2018
** which
** File description:
** gaspacho andalou
*/

#include "../../include/my_sh.h"

int	my_which(t_mini *mini, NOU node **head)
{
	int	i = -1;

	if (!mini->tab[1]) {
		write(2, "wich: Too few arguments.\n", 25);
		mini->global = 1;
		return (1);
	}
	while (mini->alias &&mini->alias[++i]) {
		if (strcmp(mini->tab[1], mini->alias[i][1]) == 0) {
			printf("%s:\t is aliased to %s\n",
			mini->tab[1], mini->alias[i][1]);
			return (0);
		}
	}
	return (1);
}
