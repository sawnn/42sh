/*
** EPITECH PROJECT, 2018
** str to word tab
** File description:
** gaspacho andalou
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	count_words(char *str, char sep)
{
	int	i = -1;
	int	words = 0;

	while (str[++i] != '\0') {
		if (str && str[i + 1] && str[i] == sep && str[i + 1] != '\0')
			words += 1;
	}
	return (words + 1);
}

int	count_l(char *str, char sep)
{
	int	i = -1;
	int	letter = 0;

	while (str[++i] == ' ');
	i -= 1;
	while (str[++i] != sep && str[i] != 0)
		letter += 1;
	return (letter);
}

char	*my_strndup(char *str, int n)
{
	int	i = -1;
	char	*tmp = NULL;

	if ((tmp = malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	while (++i != n)
		tmp[i] = str[i];
	tmp[i] = 0;
	return (tmp);
}

char	**my_str_to_wordtab(char *str, char sep)
{
	int	nb_words = count_words(str, sep) + 1;
	char	**tab = NULL;
	int	i = -1;
	int	j = 0;
	int	k = 0;
	char	*tmp = str;

	if ((tab = malloc(sizeof(char *) * nb_words + sizeof(char *))) == NULL)
		return (NULL);
	while (++i < nb_words - 1) {
		k = count_l(tmp, sep);
		tab[j] = my_strndup(tmp, k);
		tmp = &tmp[k + 1];
		j += 1;
	}
	tab[j] = NULL;
	return (tab);
}
