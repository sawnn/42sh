/*
** EPITECH PROJECT, 2018
** my_echo
** File description:
** gaspacho andalou
*/

#include "my.h"

int	find_slash(char *str)
{
	int	i = -1;

	while (str[++i] != 0)
		if (str[i] == '\\')
			return (1);
	return (0);
}

int	my_echo(char **av)
{
	int	i = 0;

	if (parse_error(av) == 84)
		return (84);
	if (is_special(av) == 1) {
		special_char(av);
		return (0);
	}
	while (av[++i]) {
		write(1, av[i], strlen(av[i]));
		av[i + 1] ? write(1, " ", 1) : 0;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2) {
		write(1, "\n", 1);
		return (0);
	}
	if (my_echo(av) == 84)
		return (84);
	write(1, "\n", 1);
	return (0);
}
