/*
** EPITECH PROJECT, 2018
** checks
** File description:
** gaspacho andalou
*/

#include "my.h"

int	check_name(char **tab)
{
	int	i = -1;

	while (tab[1][++i] != '\0') {
		if ((tab[1][i] < 48 || tab[1][i] > 57)
			&& (tab[1][i] < 65 || tab[1][i] > 90)
			&& (tab[1][i] < 97 || tab[1][i] > 122)) {
			write(2, tab[0], my_strlen(tab[0]));
			write(2, ": Variable name must contain", 28);
			write(2, " alphanumeric characters.\n", 26);
			call_exit(1);
			return (1);
		}
	}
	return (0);
}
