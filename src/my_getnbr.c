/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** my_getnbr.c
*/

#include "../include/my_minishell.h"

int	my_getnbr(char *str)
{
	int	nb = 0;
	int	isneg = 1;
	int	i = 0;

	while (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-')
			isneg = isneg * -1;
		i = i + 1;
	}
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9') {
			nb = nb * 10;
			nb = nb + str[i] - '0';
			i = i + 1;
		}
		else
			return (86);
	}
	return (nb * isneg);
}
