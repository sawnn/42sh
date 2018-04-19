/*
** EPITECH PROJECT, 2017
** get_nbr
** File description:
** get_nbr
*/

#include "my.h"

int	is_it_num(char x)
{
	if (x >= '0' && x <= '9')
		return (1);
	else if (x == '-')
		return (3);
	return (0);
}

int	my_getnbr(char const *str)
{
	int	i = 0;
	int	minus = 1;
	int	nb = 0;

	while (str[i] != '\0' && is_it_num(str[i])) {
		if (is_it_num(str[i]) == 1)
			nb = ((nb * 10) + str[i] - 48);
		else if (is_it_num(str[i]) == 3)
			minus = -minus;
		i = i + 1;
	}
	return (nb * minus);
}
