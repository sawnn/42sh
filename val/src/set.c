/*
** EPITECH PROJECT, 2018
** set
** File description:
** .c
*/

#include "../include/shell.h"

int	count_tab(char **tab)
{
	int i = 0;

	while (tab[i])
		i += 1;
	printf("i = %d\n", i);
	return (i);
}

void	no_space(char *str, t_shell *sh)
{
	char **tab = NULL;

	if (check_egual(str) == 1)
		return;
	tab = my_str_to_wordtab(str, '=');
	if (tab[0] && tab[1])
		sh->list = add_link(sh->list, tab[0], tab[1]);
	print_list(sh->list);
}

void	with_space(char **tab, t_shell *sh)
{
	if (check_egual_tab(tab) == 1)
		return;
	if (count_tab(tab) == 3)
		if (strcmp(tab[0], "=") != 0 && strcmp(tab[1], "=") == 0 &&
			strcmp(tab[2], "=") != 0)
			sh->list = add_link(sh->list, tab[0], tab[2]);
	print_list(sh->list);
}

void	fct_set(char **tab, char **env, t_shell *sh)
{
	if (count_tab(tab) == 1)
		no_space(tab[0], sh);
	else if (count_tab(tab) > 1)
		with_space(tab, sh);
}
