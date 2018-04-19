/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
	int	i = 0;
	int	a = my_strlen(s1);
	int	b = my_strlen(s2);

	if (a != b)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0') {
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		i = i + 1;
	}
	return (0);
}
