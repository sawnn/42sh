/*
** EPITECH PROJECT, 2017
** putstrerror
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

int	my_putstr_error(char *str, t_list *i)
{
	int	x = -1;

	while (str[++x] != '\0') {
		my_putchar_error(str[x], i);
	}
	return (0);
}
