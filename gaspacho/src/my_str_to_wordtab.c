/*
** EPITECH PROJECT, 2018
** st_to_wordtab
** File description:
** gaspacho andalou
*/

#include "my.h"

int	count_words(char *str, char sep)
{
	int	i = -1;
	int	words = 0;

	while (str[++i] != '\0') {
		if (str[i] == sep && str[i + 1] != '\0')
			words += 1;
	}
	return (words + 1);
}

int	count_l(char *str, char sep)
{
	int	i = -1;

	while (str[++i] != '\0') {
		if (str[i] == sep)
			return (i);
	}
	return (i);
}

void	my_strncpy(char *src, char *dest, int n)
{
	int	i = -1;

	while (++i < n)
		dest[i] = src[i];
	dest[i] = '\0';
}

int	count_tabs(char **tab)
{
	int	i = -1;

	while (tab[++i] != NULL);
	return (i);
}

char	**my_str_to_wordtab(char *str, char sep)
{
	int	i = -1;
	int	j = 0;
	int	k = count_words(str, sep) + 1;
	char	**tab = NULL;
	int	z = 0;

	if ((tab = malloc(sizeof(char*) * k + sizeof(char *))) == NULL)
		return (NULL);
	while (str[++i] != '\0') {
		if (str[i] != sep && z == 0) {
			tab[j] = my_memset(tab[j], count_l(&str[i], sep));
			my_strncpy(&str[i], tab[j], count_l(&str[i], sep));
			j += 1;
			z = 1;
		}
		else if (str[i] == sep)
			z = 0;
	}
	tab[j] = NULL;
	return (tab);
}
