/*
** EPITECH PROJECT, 2018
** which
** File description:
** gaspacho andalou
*/

#include "../../include/my_sh.h"

char	**which_tab(void)
{
	char	**tab = NULL;

	if ((tab = malloc(sizeof(char *) * 10)) == NULL)
		return (NULL);
	tab[0] = "exit";
	tab[1] = "setenv";
	tab[2] = "unsetenv";
	tab[3] = "echo";
	tab[4] = "cd";
	tab[5] = "which";
	tab[6] = "where";
	tab[7] = NULL;
	return (tab);
}

int	find_shell_built(char *str)
{
	char	**tab = which_tab();
	int	i = -1;

	while (tab[++i] != NULL)
		if (strcmp(tab[i], str) == 0)
			return (1);
	return (0);
}

int	my_which(t_mini *mini, NOU node **head)
{
	int	i = -1;
	if (!mini->tab[1]) {
		write(2, "which: Too few arguments.\n", 26);
		mini->global = 1;
		return (1);
	} else if (find_shell_built(mini->tab[1]) > 0) {
		mini->wh == 1 ? printf("%s: shell built-in command.\n",
					mini->tab[1]) : 0;
		mini->wh == 2 ? printf("%s is a shell built-in\n",
					mini->tab[1]) : 0;
		return (0);
	}
	while (mini->alias && mini->alias[++i]) {
		if (strcmp(mini->tab[1], mini->alias[i][1]) == 0) {
			printf("%s:\t  %s is aliased to %s\n",
			mini->b_ali[1], mini->b_ali[1], mini->alias[i][1]);
			return (0);
		}
	}
	mini->work = 0;
	my_where(mini, head);
	return (1);
}
