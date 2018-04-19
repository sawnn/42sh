/*
** EPITECH PROJECT, 2017
** my_str_isalpha.c
** File description:
** my_str_isalpha.c
*/

#include "my.h"

int	my_str_isalpha(char const *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if ((str[i] < 'A' || str[i] > 'Z') &&
			(str[i] < 'a' || str[i] > 'z'))
			return (0);
		i = i + 1;
	}
	return (1);
}
