/*
** EPITECH PROJECT, 2018
** strdup
** File description:
** strdup
*/

#include "my.h"

char	*my_strdup(char *str)
{
	int n = -1;
	char *ret;

	if ((ret = malloc(my_strlen(str) + 1)) == NULL)
		return (NULL);
	while (str[++n])
		ret[n] = str[n];
	ret[n] = 0;
	return (ret);
}
