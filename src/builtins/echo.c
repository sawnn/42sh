/*
** EPITECH PROJECT, 2018
** echo.c
** File description:
** a
*/

#include "../../include/my_sh.h"

int	find_char(char *str, char c)
{
	int	i = -1;

	while (str[++i] != 0)
		if (str[i] == c)
			return (1);
	return (0);
}

int	len_tab(char **tab)
{
	int	i = -1;

	while (tab[++i] != NULL);
	return (i);
}

int	get_echo(char **av)
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
	if (str[0] == '-')
		return (str[1] == 'n' ? 1 : 0);
	return (0);
}

int	my_echo(t_mini *mini, NOU node **head)
{
	char **tab = mini->tab;
	int	len = len_tab(tab);

	if (len < 2) {
		write(1, "\n", 1);
		return (0);
	}
	if (get_echo(is_n(tab[1]) == 0 ? tab : &tab[1]) == 84)
		return (84);
	is_n(tab[1]) == 0 ? write(1, "\n", 1) : 0;
	return (0);
}
