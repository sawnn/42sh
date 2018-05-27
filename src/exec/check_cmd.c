/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Check CMD, pointeur fonction
*/

#include "../../include/my_sh.h"

int	check_cmd(t_mini *mini, node **head)
{
	int i = 0;

	if ((mini->tab = my_glob(mini->tab)) == NULL)
		return ((mini->global = 1));
	if ((i = is_builtins(mini, head)) != -1)
		mini->global = i;
	else if (check_path(mini, head, 0) == 0) {
		mini->head = head;
		mini->is_exec == 0 ? mini->global = which_exec(mini) : 0;
	}
	else {
		write(2, mini->tab[0], strlen(mini->tab[0]));
		write(2, ": Command not found.\n", 21);
		mini->global = 1;
	}
	return (mini->global);
}
