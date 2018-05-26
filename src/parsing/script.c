/*
** EPITECH PROJECT, 2018
** script.c
** File description:
** a
*/

#include "../../include/my_sh.h"

int	my_comp(char *s1, char *s2)
{
	int	i = -1;

	while (s1[++i] != 0)
		if (s1[i] != s2[i])
			return (84);
	return (0);
}

int	check_shebang(char *str)
{
	int	i = -1;

	while (str[++i] != 0)
		if (my_comp(&str[i], "42sh") == 0)
			return (1);
	return (0);
}

int	check_sh(char *str)
{
	int	i = -1;

	while (str[++i] != 0);
	i -= 1;
	if (str[i] == 'h' && str[i - 1] == 's')
		return (1);
	return (0);
}

int	is_script(char *str)
{
	int	fd = open(&str[2], O_RDONLY);
	char	*tmp = NULL;

	if (fd != -1 && check_sh(str) == 1)
		tmp = get_next_line(fd);
	else
		return (0);
	if (fd != -1 && check_shebang(tmp) == 1) {
		free(tmp);
		return (fd);
	}
	free(tmp);
	return (0);
}
