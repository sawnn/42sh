/*
** EPITECH PROJECT, 2017
** check_flag
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

int	check_flag_printf(char flag)
{
	char	str[12] = "diouxXbcsSp%";
	int	i = -1;

	while (str[++i] != '\0') {
		if (str[i] == flag)
			return (i);
	}
	return (84);
}
