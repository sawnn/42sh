/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

int	my_putstr(char *str, t_list *i)
{
	int	x = 0;

	if (str == NULL)
		return (84);
	while (str[x] != '\0') {
		my_putchar(str[x], i);
		x += 1;
	}
	return (0);
}
