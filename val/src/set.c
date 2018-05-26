/*
** EPITECH PROJECT, 2018
** set
** File description:
** .c
*/

#include "../include/shell.h"

int	count_tab(char **tab)
{
	int i = 0;

	while (tab[i])
		i += 1;
	return (i);
}

void	no_space(char *str, t_shell *sh)
{
	char **tab = NULL;

	if (check_egual(str) == 1)
		return;
	tab = my_str_to_wordtab(str, '=');
	if (tab[0] && tab[1])
		sh->list = add_link(sh->list, tab[0], tab[1]);
	print_list(sh->list);
}

void	with_space(char **tab, t_shell *sh)
{
	if (check_egual_tab(tab) == 1)
		return;
	if (count_tab(tab) == 3)
		if (strcmp(tab[0], "=") != 0 && strcmp(tab[1], "=") == 0 &&
			strcmp(tab[2], "=") != 0)
			sh->list = add_link(sh->list, tab[0], tab[2]);
	print_list(sh->list);
}

void	fct_set(char **tab, char **env, t_shell *sh)
{
	if (count_tab(tab) == 1)
		no_space(tab[0], sh);
	else if (count_tab(tab) > 1)
		with_space(tab, sh);
}

int	main(int ac, char **av, char **env)
{
	t_shell *sh;
	char *str = NULL;

	if ((sh = malloc(sizeof(t_shell))) == NULL) {
		printf("la\n");
		return (84);
	}
	if (ac == 1) {
		printf("ici\n");
		return (84);
	}
	if (strcmp(av[1], "set") == 0)
		fct_set(&av[2], env, sh);
	printf("%c\n", av[1][0]);
	if (av[1][0] == '$') {
		sh->list = add_link(sh->list, "val", "delcroix");
		sh->list = add_link(sh->list, "zack", "folle");
		sh->list = add_link(sh->list, "daniel", "ramadan");
		str = dollars(&av[1][1], sh->list);
		if (str)
			printf("%s\n", str);
	}
	else
		return (84);
	return (0);
}
