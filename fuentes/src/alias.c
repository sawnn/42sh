/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** Alias
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

char	*my_strncpy(char *src, int start, int end)
{
	char *dest = malloc(sizeof(char) * end+1);
	int	a = -1;

	src[start] == ' ' ? start += 1: 0;
	while (src[++a] && a < end) {
		dest[a] = src[start];
		start += 1;
	}
	dest[a] = '\0';
	return (dest);
}

int	count_alias(char *str)
{
	int	a = 5;
	int	word = 0;

	while (str[++a])
		if (str[a] == ' ')
			word += 1;
	return (word);
}

char	**is_space(char *str, int *a, int b)
{
	char	*save = malloc(sizeof(char) * strlen(str) + 1);
	static	int	savezer;
	static	int	saveis = 0;

	b == 0 ? (savezer = 0) : (savezer = saveis);
	while (str[*a] && str[++*a] != ' ');
	saveis = *a;
	save = my_strncpy(str, savezer, *a);
	return (my_str_to_word_tab(save, ' '));
}

char	***put_in(char *str, char ***tab)
{
	int	a = 0;
	int	b = 0;

	while (str[++a]) {
		if (str[a] == ' ') {
			tab[b] = is_space(str, &a, b);
			tab[b][3] = NULL;
			b += 1;
			a += 1;
		}
	}
	b += 1;
	tab[b] = NULL;
	return (tab);
}

void	alias_func(use_value *use)
{
	int	quotes = 0;
	quotes = count_alias(use->epured);
	use->alias = malloc(sizeof(char **) * quotes);
	use->alias = put_in(use->epured+6, use->alias);
	print_tab(use->alias[0]);
	printf("------------------\n");
	print_tab(use->alias[1]);
}
