/*
** EPITECH PROJECT, 2018
** semicolons
** File description:
** .c
*/

#include "../include/my.h"
#include "../include/shell.h"

int	nb_semicolons(t_value *sh)
{
	int i = 0;
	int nb = 0;

	while (sh->tmp[i]) {
		if (sh->tmp[i] == ';')
			nb += 1;
		i += 1;
	}
	return (nb);
}

char	*epur_separation(char *str)
{
	char *tmp = malloc(sizeof(char) * my_strlen(str) + 1);
	int i = 0;
	int j = 0;

	while (str[i]) {
		if (str[i] == ' ' && str[i - 1] == ';'
			|| str[i] == ' ' && str[i + 1] == ';')
			i += 1;
		else {
			tmp[j] = str[i];
			j += 1;
			i += 1;
		}
	}
	return (tmp);
}

int	check_semicolons(t_value *sh, char **env, int *checky, int *path)
{
	char **tab;
	int i = 0;

	sh->tmp = epur_separation(sh->tmp);
	tab = my_str_to_wordtab(sh->tmp, ';');
	while (tab[i]) {
		sh->tmp = tab[i];
		if (tab[i + 1] != NULL)
			sh->prompt = 1;
		if (my_shell(sh, env, checky, path) == 0)
			return (0);
		i += 1;
		sh->prompt = 0;
	}
	return (1);
}
