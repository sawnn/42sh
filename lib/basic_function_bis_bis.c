/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Basic_3
*/

#include "../include/my_sh.h"

int	length_tab(char **tab)
{
	int	i = -1;

	while (tab[++i] != NULL);
	return (i);
}
