/*
** EPITECH PROJECT, 2017
** lib
** File description:
** my_putstr
*/

#include "my.h"

int	my_putstr(char const *str)
{
	int	a = -1;

	if (!str)
		return (0);
	while (str[++a])
		my_putchar(str[a]);
	return (0);
}
