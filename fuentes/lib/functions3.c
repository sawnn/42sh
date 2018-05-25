/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** functions
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

void	print_tab(char **tab)
{
	int	a = -1;

	while (tab[++a])
		my_printf("%s\n", tab[a]);
}

int	size_tab(char **tab)
{
	int	a = -1;

	if (!tab)
		return (-1);
	while (tab[++a]);
	return (a);
}
