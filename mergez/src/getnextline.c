/*
** EPITECH PROJECT, 2018
** getnextline
** File description:
** getnextline
*/

#include "../include/my.h"

void	pars(char **tab, int *i, int *j, int *stick)
{
	if (tab[*j][*i] == '|')
		*stick += 1;
	*i += 1;
}

int	win_lose(char **tab)
{
	int i = 0;
	int j = 0;
	int stick = 0;

	while (tab[j]) {
		while (tab[j][i] != '\0') {
			pars(tab, &i, &j, &stick);
		}
		i = 0;
		j += 1;
	}
	return (stick);
}

char	*get_next_line(int fd)
{
	char *buffer;
	char *save;
	int ret = 1;

	if ((save = malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	if ((buffer = malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	while (ret == 1) {
		if ((ret = read(fd, buffer, 1)) == 0)
			return (NULL);
		if (buffer[0] == '\n')
			ret = 0;
		else
			save = my_strcat(save, buffer);
	}
	return (save);
}
