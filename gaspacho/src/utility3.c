/*
** EPITECH PROJECT, 2018
** utility 3
** File description:
** gaspacho andalou
*/

#include "my.h"

int	my_getnbr(char *str)
{
	int	i = -1;
	int	total = 0;
	int	tmp = 0;

	while (str[++i]) {
		if (str[i] >= 48 && str[i] <= 57)
			tmp = str[i] - 48;
		total = total * 10 + tmp;
	}
	if (str[0] == '-')
		total = total * (-1);
	return (total);
}
