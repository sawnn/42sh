/*
** EPITECH PROJECT, 2018
** input
** File description:
** gaspacho andalou
*/

#include "my.h"

void	handle_input(t_shell *shell)
{
	char	**tab = NULL;
	int	i = -1;

	call_exit(0);
	tab = semicolon(shell->input);
	if (!tab) {
		shell->tab = my_str_to_wordtab(shell->input, ' ');
		find_command(shell);
	}
	else {
		while (tab[++i]) {
			shell->input = tab[i];
			shell->tab = my_str_to_wordtab(shell->input, ' ');
			find_command(shell);
		}
	}
}
