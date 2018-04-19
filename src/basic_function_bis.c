/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my_minishell.h"

void	print_tab(char **tab)
{
	int	i = - 1;

	while (tab[++i] != NULL) {
		my_printf("%s\n", tab[i]);
	}
}

char	*my_strdup(char *dest, char *src)
{
	int	i = -1;

	dest = malloc(sizeof(char) * my_strlen(src) + 1);
	if (!dest)
		return (NULL);
	while (src[++i] != '\0') {
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
