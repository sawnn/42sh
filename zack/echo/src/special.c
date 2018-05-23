/*
** EPITECH PROJECT, 2018
** special
** File description:
** gaspacho andalou
*/

#include "my.h"

int	is_special(char **av)
{
	int	i = -1;

	while (av[++i])
		if (find_slash(av[i]) == 1)
			return (1);
	return (0);
}

char	get_special(char c)
{
	char	*str = "abcfnrtv\\";
	char	*special = NULL;
	int	i = -1;

	if ((special = malloc(sizeof(char) * 10)) == NULL)
		return (-1);
	special[0] = '\a';
	special[1] = '\b';
	special[3] = '\f';
	special[4] = '\n';
	special[5] = '\r';
	special[6] = '\t';
	special[7] = '\v';
	special[8] = '\\';
	special[9] = 0;
	while (str[++i] != 0)
		if (str[i] == c)
			return (special[i]);
	return (-1);
}

int	replace_special(char *str)
{
	int	i = -1;
	char	c = 0;

	while (str[++i] != 0) {
		if (str[i] == '\\') {
			c = get_special(str[i + 1]);
			write(1, &c, 1);
			i += 1;
		} else
			write(1, &str[i], 1);
	}
	return (0);
}

int	special_char(char **av)
{
	int	i = 0;

	while (av[++i]) {
		if (find_slash(av[i]) == 1)
			replace_special(av[i]);
		else
			write(1, av[i], strlen(av[i]));
		av[i + 1] ? write(1, " ", 1) : 0;
	}
	return (0);
}
