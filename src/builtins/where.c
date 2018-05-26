/*
** EPITECH PROJECT, 2018
** where
** File description:
** gaspacho andalou
*/

#include "../../include/my_sh.h"

int	my_where(t_mini *mini, NOU node **head)
{
	char	**tab = my_str_to_wordtab(mini->fullpath, ':');
	int	i = -1;
	char	*tmp = NULL;

	my_which(mini, head);
	while (tab[++i] != NULL) {
		tmp = strcat(tab[i], "/");
		tmp = strcat(tmp, mini->tab[1]);
		if (access(tmp, F_OK) == 0) {
			printf("%s\n", tmp);
			free(tmp);
			return (0);
		}
		free(tmp);
	}
	return (1);
}
