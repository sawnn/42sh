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

int	is_num(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9')
			i += 1;
		else
			return (-1);
	}
	return (1);
}
