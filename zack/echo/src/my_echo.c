/*
** EPITECH PROJECT, 2018
** my_echo
** File description:
** gaspacho andalou
*/

#include "my.h"

int	find_char(char *str, char c)
{
	int	i = -1;

	while (str[++i] != 0)
		if (str[i] == c)
			return (1);
	return (0);
}

int	my_echo(char **av)
{
	int	i = 0;

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

int	is_n(char *str)
{
	int	i = -1;

	if (str[0] == '-')
		return (str[1] == 'n' ? 1 : 0);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2) {
		write(1, "\n", 1);
		return (0);
	}
	if (my_echo(is_n(av[1]) == 0 ? av : &av[1]) == 84)
		return (84);
	is_n(av[1]) == 0 ? write(1, "\n", 1) : 0;
	return (0);
}
