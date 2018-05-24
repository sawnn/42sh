/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** epur_str
*/

#include "../include/my_sh.h"

char	*my_epure_str(char *str)
{
	char	*tmp = NULL;
	int	i = 0;
	int	j = 0;

	if ((tmp = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
		return (NULL);
	while ((str[i] == ' ') || (str[i] == '\t'))
		i = i + 1;
	while (str[i] != '\0') {
		tmp[j++] = str[i++];
		while ((str[i] == ' ') || (str[i] == '\t'))
			i = i + 1;
		if (((str[i - 1] == ' ') || (str[i - 1] == '\t'))
			&& (str[i] != '\0')) {
			tmp[j] = ' ';
			j = j + 1;
		}
	}
	tmp[j] = '\0';
	return (tmp);
}
