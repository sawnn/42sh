/*
** EPITECH PROJECT, 2018
** str to word tab
** File description:
** minishell
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

int	count_word_or(char *envi, char param)
{
	int	a = 0;
	int	n = 0;

	if (!envi)
		return (0);
	while (envi[a] != '\0' && envi[a] != '\n') {
		if (envi[a] == param && envi[a + 1] != '\0')
			n = n + 2;
		a = a + 1;
	}
	return (n);
}

int	count_char_or(char *envi, char param)
{
	int	b = 0;

	while ((envi[b] != param) && (envi[b] != '\0') && (envi[b] != '\n'))
		b = b + 1;
	if (envi[b+1] == param) {
		b = b + 1;
		return (b);
	}
	return (0);
}

void	while1_or(char *envi, char param, int *a, int *i)
{
	while (envi[*a] == param)
		*a = *a + 2;
	*i = *i + 1;
}

char	**word_tab_or(char *envi, char param)
{
	int	a = 0;
	int	b = 0;
	int	i = 0;
	char	**tab =malloc(sizeof(char*) * (count_word_or(envi, param) + 2));
	if (!envi || count_word_or == 0)
		return (NULL);
	while (envi[a] != '\0') {
		if (envi[a] == param  || envi[a] == '\n') {
			while1_or(envi, param, &a, &i);
			b = 0;
		}
		tab[i] = malloc(sizeof(char) *
					((count_char_or(envi + a, param) + 1)));
		while ((envi[a] != param)  && (envi[a] != '\n')
			&& (envi[a] != '\0'))
			tab[i][b++] = envi[a++];
		tab[i][b] = '\0';
	}
	tab[i + 1] = 0;
	return (tab);
}
