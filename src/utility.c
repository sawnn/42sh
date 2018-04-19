/*
** EPITECH PROJECT, 2018
** utility
** File description:
** a
*/

#include "../include/my_minishell.h"

char    *my_strncat(char *dest, char *src, int nb)
{
	int i = 0;
	int t1 = -1;

	while (dest[++t1] != '\0');
	while (i < nb && src[i]) {
		dest[t1 + i] = src[i];
		i++;
	}
	dest[t1 + i] = '\0';
	return (dest);
}

int     glob(int i)
{
	static int glob = 0;

	if (i != -2)
		glob = i;
	return (glob);
}
