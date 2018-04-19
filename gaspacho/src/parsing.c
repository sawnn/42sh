/*
** EPITECH PROJECT, 2018
** parsing
** File description:
** gaspacho andalou
*/

#include "my.h"

int	find_semicolon(char *str)
{
	int	i = -1;
	int	j = 0;

	while (str[++i])
		str[i] == ';' ? j += 1 : 0;
	return (j);
}

char	**semicolon(char *input)
{
	char	**tab = NULL;

	if (find_semicolon(input) > 0) {
		input = my_epure_str(input);
		tab = my_str_to_wordtab(input, ';');
	}
	return (tab);
}
