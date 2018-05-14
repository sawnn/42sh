/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** with_param
*/

#include <stdio.h>
#include <stdlib.h>

int	alp(char *str, char c, int i)
{
	int	j = i;

	if (str[i] > 32 && str[i] != 127 && str[i] != c) {
		while (str[i] > 32 && str[i] != 127 && str[i] != c)
			i = i + 1;
	}
	return (i - j);
}

int	compt_word(char *str, char c)
{
	int	i = 0;
	int	word = 0;

	while (str[i] != '\0') {
		while (str[i] != '\0' && str[i++] == c);
		++word;
		while (str[i] != '\0' && str[i++] != c);
	}
	return (word);
}

int	skip_escape_bis(char *str, int i)
{
	if (str[i] == ' ') {
		while (str[i] == ' ')
			i = i + 1;
	}
	return (i);
}

char	**my_str_to_word_tab_sep(char *s, char c)
{
	int	i = 0;
	int	x = 0;
	int	y = 0;
	int	word = compt_word(s, c);
	char	**tab = malloc(sizeof(char *) * word + sizeof(char *));
	if (!tab)
		return (NULL);
	while (y != word) {
		i = skip_escape_bis(s, i);
		if ((tab[y] = malloc(sizeof(char) * alp(s, c, i) + 1)) == NULL)
			return (NULL);
		while (s[i] > 32 && s[i] != c && s[i] != '\0')
			tab[y][x++] = s[i++];
		tab[y][x] = '\0';
		i = i + 1;
		y = y + 1;
		x = 0;
	}
	tab[y] = NULL;
	return (tab);
}
