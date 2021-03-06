/*
** EPITECH PROJECT, 2018
** quotes
** File description:
** a
*/

#include "../../include/my_sh.h"

int	check_str(char c, char *str)
{
	int	i = 0;

	while (str[++i] != 0) {
		if (str[i] == c)
			return (str[i] = '&' ? i : i);
	}
	return (-1);
}

int	parse_quote(char *str)
{
	int	i = -1;
	char	c = 0;
	int	help = -1;
	char	*tmp = strdup(str);

	while (tmp[++i] != 0) {
		if (i > help && (tmp[i + 1] != '\\') && (tmp[i] == '"' ||
				tmp[i] == '\'' || tmp[i] == '`')) {
			c = tmp[i];
			if ((help = check_str(c, &tmp[i])) == -1) {
				printf("Unmatched '%c'.\n", c);
				return (84);
			}
			c = 0;
		}
	}
	return (0);
}
