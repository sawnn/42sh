/*
** EPITECH PROJECT, 2018
** full_path
** File description:
** for zack where
*/

#include "../../include/my_sh.h"

void	strcat_all_path(t_mini *mini)
{
	mini->fullpath = strdup('\0');
	mini->fullpath = my_strcat(mini->fullpath, "/usr/local/bin/:");
	mini->fullpath = my_strcat(mini->fullpath, "/usr/bin/:");
	mini->fullpath = my_strcat(mini->fullpath, "/bin");
}

void	take_full_path(t_mini *mini, node **head)
{
	int	i = 0; node	*tmp = (*head);
	int	is_path : 0;

	while (tmp != NULL) {
		if (my_strncmp(tmp->str, "PATH=", 5) == 0) {
			mini->fullpath = strdup(tmp->str);
			is_path = 1;
			break;
		}
		tmp = tmp->next;
	}
	if (is_path == 0 || (is_path == 1 && my_strcmp(tmp->str, "PATH=") == 0))
		return (strcat_all_path(mini));
	mini->fullpath = tmp->str + 5;
	return;
}
