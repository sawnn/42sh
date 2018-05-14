/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** no_param
*/

#include "../include/my_minishell.h"

int	num_word(char *str)
{
	int	i = 0;
	int	word = 0;

	while (str[i] != '\0') {
		while (str[i] != '\0' && str[i++] == ' ');
		++word;
		while (str[i] != '\0' && str[i++] > ' ');
	}
	return (word);
}

int	n_cha(char *str, int i)
{
	int	j = i;

	if (str[i] > 32 && str[i] != 127) {
		while (str[i] > 32 && str[i] != 127)
			i++;
	}
	return (i - j);
}

int	skip_escape(char *str, int i)
{
	if (str[i] == ' ') {
		while (str[i] == ' ')
			i = i + 1;
	}
	return (i);
}

char	**my_str_to_word_array(char *str)
{
	int	i = 0;
	int	x = 0;
	int	y = 0;
	int	word = num_word(str);
	char	**tab = malloc(sizeof(char *) * word + (sizeof(char *) * 2));
	if (!tab)
		return (NULL);
	while (y != word) {
		i = skip_escape(str, i);
		if ((tab[y] = malloc(sizeof(char) * n_cha(str, i) + 1)) == NULL)
			return (NULL);
		while (str[i] > 32 && str[i] != '\0')
			tab[y][x++] = str[i++];
		tab[y][x] = '\0';
		i = i + 1;
		y = y + 1;
		x = 0;
	}
	tab[word] = NULL;
	return (tab);
}
