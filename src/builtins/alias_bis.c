/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** Alias
*/

#include "../../include/my_sh.h"

char	**replace_alias(char **tab, t_mini *mini)
{
	int	a = -1; int	b = -1;
	int	c = 0; int	d = 0;
	char	**save = malloc(sizeof(char *) * 1000);

	if (mini->alias == NULL)
		return (tab);
	while (tab[++a]) {
		b = -1;
		save[d] = strdup(tab[a]);
		while (mini->alias[++b] && mini->alias[b][0]) {
			if ((strcmp(tab[a], mini->alias[b][0]) == 0)) {
				while (mini->alias[b][++c]) {
					save[d] = strdup(mini->alias[b][c]);
					d += 1;
				}
				c = 0; continue;
			}
		}
		d += 1; b = -1;
	} return (save);
}

int	alias_lenght(char **tab)
{
	int	a = -1;

	if (!tab)
		return (0);
	while (tab[++a]);
	return (a);
}
