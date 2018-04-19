/*
** EPITECH PROJECT, 2018
** redirections
** File description:
** gaspacho andalou
*/

#include "my.h"

void	apply_redirection(int i, t_shell *shell, char *output)
{
	void	(*fptr[5])(t_shell *, char *);

	fptr[0] = &simple_right;
	fptr[1] = &simple_left;
	fptr[2] = &double_right;
	fptr[3] = &double_left;
	fptr[4] = NULL;
	fptr[i](shell, output);
}

int	is_redirection(char *input)
{
	char	**tab = NULL;
	int	i = -1;

	if ((tab = malloc(sizeof(char *) * 5)) == NULL)
		return (-1);
	tab[0] = ">";
	tab[1] = "<";
	tab[2] = ">>";
	tab[3] = "<<";
	tab[4] = NULL;
	while (tab[++i]) {
		if (my_strcmp(tab[i], input) == 0) {
			return (i);
		}
	}
	return (-1);
}

int	redirections(t_shell *shell)
{
	int	i = -1;
	int	a = 0;
	int	b = 0;

	while (b == 0 && shell->tab[++i] != NULL) {
		if ((a = is_redirection(shell->tab[i])) >= 0) {
			shell->glob = i;
			apply_redirection(a, shell, shell->tab[i + 1]);
			shell->tab[i] = NULL;
			return (1);
		}
	}
	return (0);
}
