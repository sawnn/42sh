/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** my_strlen.c
*/

#include "../include/my_printf.h"

int	my_strlen(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i = i + 1;
	return (i);
}
