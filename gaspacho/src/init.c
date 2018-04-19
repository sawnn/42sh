/*
** EPITECH PROJECT, 2018
** init
** File description:
** gaspacho andalou
*/

#include "my.h"

char	**tab_command(void)
{
	char	**tab = NULL;

	if ((tab = malloc(sizeof(char*) * 6)) == NULL)
		return (NULL);
	tab[0] = "env";
	tab[1] = "setenv";
	tab[2] = "unsetenv";
	tab[3] = "cd";
	tab[4] = "exit";
	tab[5] = NULL;
	return (tab);
}
