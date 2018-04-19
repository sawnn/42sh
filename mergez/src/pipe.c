/*
** EPITECH PROJECT, 2018
** pipe
** File description:
** .c
*/

#include "../include/my.h"
#include "../include/shell.h"
#include <sys/wait.h>

int	count_pipe(char **tab, t_value *sh)
{
	int nb = 0;
	int i = 0;

	while (tab[i]) {
		if (my_strcmp(tab[i], "|") == 0)
			nb += 1;
		if (my_strcmp(tab[i], "|") == 0 && tab[i + 1] == NULL) {
			my_printf("Invalid null command.\n");
			sh->exit = 1;
			return (-1);
		}
		i += 1;
	}
	return (nb + 1);
}

void	check_envi(t_value *sh, char **env, char *str)
{
	sh->i = 0;
	sh->strcat = my_strcat(sh->path[sh->i], my_strcat("/", str));
	while (access(sh->strcat, F_OK) == -1 &&
		sh->i < (count_path(sh->path) - 1)) {
		sh->i += 1;
		sh->strcat = my_strcat(sh->path[sh->i], my_strcat("/", str));
	}
}

int	nb_line(char **tab)
{
	int i = 0;

	while (tab[i])
		i += 1;
	return (i);
}

char	**cp_tab(char **tab, char **big_tab)
{
	int i = 0;

	while (tab[i]) {
		big_tab[i] = tab[i];
		i += 1;
	}
	big_tab[i] = NULL;
	return (big_tab);
}

void	triple_tab(char **tab, int nb, t_value *sh, char **env)
{
	char ***big_tab = malloc(sizeof(char **) * nb + sizeof(char **));
	int i = 0;
	int j = 0;
	int save = 0;
	while (tab[i]) {
		if (my_strcmp(tab[i], "|") == 0) {
			tab[i] = NULL;
			big_tab[j] = malloc(sizeof(char *) *
					nb_line(&tab[save]) + sizeof(char *));
			big_tab[j] = cp_tab(&tab[save], big_tab[j]);
			save = i + 1;
			j = j + 1;
		}
		i += 1;
	}
	big_tab[j] = malloc(sizeof(char *) *
			nb_line(&tab[save]) + sizeof(char*));
	big_tab[j] = cp_tab(&tab[save], big_tab[j]);
	big_tab[nb] = NULL;
	pipe_fonction(big_tab, sh, env);
}
