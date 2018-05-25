/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../../include/my_sh.h"

char	*clear_semicolon(char *str)
{
	char	*new = NULL; int	i = 0;
	int	j = 0; int	count = 0;	char	*tmp = strdup((str));

	if ((new = malloc(sizeof(char) * my_strlen((tmp) + 1))) == NULL)
		return (NULL);
	while (tmp[i] == ';')
		i += 1;
	while (tmp[i] != '\0') {
		new[j++] = tmp[i++];
		if (tmp[i] == ';') {
			is_alph(tmp[i - 1]) == 1 ? new[j] = ' ', j += 1 : 0;
			new[j++] = tmp[i++], new[j++] = ' ';
			count = 1;
		}
		while (tmp[i] && sym(tmp[i], ';') && count == 1)
			i += 1;
		count = 0;
	}
	new[j] = '\0', str = strdup(new);
	return (str);
}

char	*clear_parentheses(char *str)
{
	char	*new = NULL; int	i = 0;
	int	j = 0; int	count = 0;	char	*tmp = strdup((str));

	if ((new = malloc(sizeof(char) * my_strlen((tmp) + 1))) == NULL)
		return (NULL);
	while (tmp[i] == ';')
		i += 1;
	while (tmp[i] != '\0') {
		new[j++] = tmp[i++];
		if (tmp[i] == '(') {
			is_alph(tmp[i - 1]) == 1 ? new[j] = ' ', j += 1 : 0;
			new[j++] = tmp[i++], new[j++] = ' ';
			count = 1;
		}
		while (tmp[i] && sym(tmp[i], ';') && count == 1)
			i += 1;
		count = 0;
	}
	new[j] = '\0', str = strdup(new);
	return (str);
}
