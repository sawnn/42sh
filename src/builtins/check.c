/*
** EPITECH PROJECT, 2018
** check
** File description:
** .c
*/

#include "../../include/shell.h"

int	check_egual(char *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] == '=')
			return (0);
		i += 1;
	}
	return (1);
}

int	check_egual_tab(char **tab)
{
	int i = 0;

	while (tab[i]) {
		if (strcmp(tab[i], "=") == 0)
			return (0);
		i += 1;
	}
	return (1);
}
