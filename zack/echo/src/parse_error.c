/*
** EPITECH PROJECT, 2018
** parse error
** File description:
** gaspacho andalou
*/

#include "my.h"

int	is_quote(char *str)
{
	int	i = -1;

	while (str[++i] != 0)
		if (str[i] == 39 || str[i] == '"')
			return (1);
	return (0);
}

int	check_quote(char **av)
{
	int	i = -1;

	while (av[++i]) {
		if (is_quote(av[i]) == 1)
			return (1);
	}
	return (0);
}

//int	parse_quote(char **av)
//{
//}

int	parse_error(char **av)
{
	if (check_quote(av) == 0)
		return (0);
	parse_quote(av);
}
