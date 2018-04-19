/*
** EPITECH PROJECT, 2017
** str_len
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

int	my_strlen(char *str)
{
	int x = 0;

	while (str[x] != '\0') {
		x += 1;
	}
	return (x);
}
