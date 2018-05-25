/*
** EPITECH PROJECT, 2018
** str to tab
** File description:
** str to tab
*/

#include "../../include/shell.h"

int	my_count_col(char *str, char c)
{
	int	n = 0;
	int	i = 0;

	while (str[n]) {
		if (str[n] == c)
			i = i + 1;
		n = n + 1;
	}
	return (i + 1);
}

int	my_count_ligne(char *str, char c)
{
	int	n = 0;

	while (str[n] && str[n] != c)
		n = n + 1;
	return (n);
}

char	**my_str_to_wordtab(char *str, char c)
{
	char	**my_tab;
	int	i = -1;
	int	n = 0;
	int	cnt = 0;

	my_tab = malloc(sizeof(char *) * (my_count_col(str, c) + 2));
	while (str[cnt] && ++i < my_count_col(str, c)) {
		n = 0;
		my_tab[i] = malloc(sizeof(char) *
				   my_count_ligne(str + cnt, c) + 2);
		while (str[cnt] != '\0' && str[cnt] != c) {
			my_tab[i][n] = str[cnt];
			cnt = cnt + 1;
			n = n + 1;
		}
		my_tab[i][++n] = 0;
		cnt = cnt + 1;
	}
	my_tab[++i] = NULL;
	return (my_tab);
}
