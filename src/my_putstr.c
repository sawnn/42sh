/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** myput
*/

#include "../include/my_minishell.h"

void	my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

int	my_strlen(char *str)
{
	int	i = -1;

	while (str[++i] != '\0');
	return (i);
}
