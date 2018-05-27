/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** path
*/

#include "../../include/my_sh.h"

int	size_tab(char **tab)
{
	int	a = -1;

	if (!tab)
		return (0);
	while (tab[++a]);
	return (a);
}
