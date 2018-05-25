/*
** EPITECH PROJECT, 2018
** callset
** File description:
** a
*/

#include "../../include/my_sh.h"

int	call_set(t_mini *mini, node **head)
{
	if ((head || !(head)) && mini->tab[1])
		fct_set(&mini->tab[1], mini->shell);
	return (0);
}

char	**check_dollar(char **tab, t_mini *mini)
{
	int i = -1;
	int j = -1;
	char *tmp;

	while (tab[++i]) {
		while (tab[i][++j])
			if (tab[i][j] == '$' && tab[i][j + 1]) {
				tmp = dollars(&tab[i][j + 1], mini->shell->list);
				if (!tmp)
					return (NULL);
				tab[i][j] = '\0';
				tab[i] = my_strcat(tab[i], tmp);
				tmp = NULL;
			}
		j = -1;
	}
	return (tab);
}
