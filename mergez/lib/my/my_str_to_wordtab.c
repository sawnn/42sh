/*
** EPITECH PROJECT, 2018
** str to tab
** File description:
** str to tab
*/

#include "my.h"
#include <unistd.h>

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

char	*epur_tab(char *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] == '\t')
			str[i] = ' ';
		i += 1;
	}
	return (str);
}

char	*epur(char *str)
{
	int i = 0;
	int j = 0;
	char *tmp = malloc(sizeof(char) * (my_strlen(str) + 2));

	str = epur_tab(str);
	while (str[i] == ' ')
		i += 1;
	while (str[i]) {
		if (str[i] == ' ') {
			tmp[j] = str[i];
			j += 1;
			while (str[i] == ' ')
				i += 1;
		}
		tmp[j] = str[i];
		i += 1;
		j += 1;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	**my_str_to_wordtab(char *str, char c)
{
	char	**my_tab;
	int	i = -1;
	int	n = 0;
	int	cnt = 0;
	str = epur(str);
	my_tab = malloc(sizeof(char *) * (my_count_col(str, c) + 1));
	while (str[cnt] && ++i < my_count_col(str, c)) {
		n = 0;
		my_tab[i] = malloc(sizeof(char) *
				my_count_ligne(str + cnt, c) + 1);
		while (str[cnt] != '\0' && str[cnt] != c) {
			my_tab[i][n] = str[cnt];
			cnt = cnt + 1;
			n = n + 1;
		}
		my_tab[i][n] = 0;
		cnt = cnt + 1;
	}
	my_tab[++i] = NULL;
	return (my_tab);
}
