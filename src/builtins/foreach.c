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
			else {
				return (-1);
			}
		}
		vue = 2;
		return (0);
	}
	/*if (vue == 1) {
		printf("zeerrrrma\n");
		while (mini->tab[i]) {
			if (my_strcmp(mini->tab[i], bis[i]) == 0)
				i += 1;
			else {
				return (-1);
				printf("different tab[%d] = %s bis = %s\n", i, mini->tab[i], bis[i]);
			}
		}
		vue = 2;
		printf("gros batard\n");
		return (0);
	}*/
	return (0);
}
