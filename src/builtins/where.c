/*
** EPITECH PROJECT, 2018
** where
** File description:
** gaspacho andalou
*/

#include "../../include/my_sh.h"

int	my_where(t_mini *mini, NOU node **head)
{
	char	**tab = NULL;
	int	i = -1;
	char	*tmp = NULL;

	take_full_path(mini, head);
	mini->fullpath[0] == 'P' ? mini->fullpath += 5 : 0;
	tab = my_str_to_word_tab_sep(mini->fullpath, ':');
	mini->wh = 2;
	mini->work == 1 ? my_which(mini, head) : 0;
	mini->wh = 1;
	while (tab && tab[++i] != NULL) {
		tmp = my_strcat(tab[i], "/");
		tmp = my_strcat(tmp, mini->b_ali[1]);
		if (access(tmp, F_OK) == 0) {
			printf("%s\n", tmp);
			if (mini->work == 0)
				break;
		}
		free(tmp);
	}
	mini->work = 1;
	return (mini->global = 0);
}
