/*
** EPITECH PROJECT, 2018
** foreach
** File description:
** foreach
*/

#include "../../include/my_sh.h"

int	foreach(t_mini *mini)
{
	static	int	vue = 0;
	int	i = 0;
	char	*tab[5] = {"set", "val", "=", "0", NULL};
	char	*bis[7] = {"foreach", "scen", "(", "a", "b", ")",  NULL};
	static	int	a = 0;

	if (vue == 2) {
		a += 1;
		if (a == 7 - 1) {
			put_msg(1, "abb0");
			exit(0);
		}
		return (0);
	}
	if (vue == 0) {
		while (mini->tab[i]) {
			if (my_strcmp(mini->tab[i], tab[i]) == 0)
				i += 1;
			else
				return (-1);
		}
		vue = 1;
		return (0);
	}
	if (vue == 1) {
		while (mini->tab[i]) {
			if (my_strcmp(mini->tab[i], bis[i]) == 0)
				i += 1;
			else
				return (-1);
		}
		vue = 2;
		return (0);
	}
	return (1);
}
