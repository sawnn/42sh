/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** Alias
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

char	**replace_alias(char **tab, use_value *use)
{
	int	a = -1;
	int	b = -1;

	if (use->alias == NULL)
		return (tab);
	while (tab[++a]) {
		while (use->alias[++b] && use->alias[b][0]) {
			if ((strcmp(tab[a], use->alias[b][0]) == 0))
				tab[a] = strdup(use->alias[b][1]);
		}
		b = -1;
	}
	return (tab);
}

int	alias_lenght(char **tab)
{
	int	a = -1;

	if (!tab)
		return (0);
	while (tab[++a]);
	return (a);
}

void	malloc_alias(char **tab, use_value *use)
{
	static	int	how = 0;
	int	size = alias_lenght(tab);

	how == 0 ? (use->alias = malloc(sizeof(char **) * 40)) : 0;
	printf("HOW = %d\n", how);
	use->alias[0] == NULL ? how = 0 : 0;
	use->alias[how] = malloc(sizeof(char *) * 3);
	use->alias[how][0] = malloc(sizeof(char) * strlen(tab[1]) + 3);
	use->alias[how][1] = malloc(sizeof(char) * strlen(tab[2]) + 3);
	use->alias[how][2] = NULL;
	how += 1;
	use->alias[how] = NULL;
}

void	put_in_alias(char **tab, use_value *use)
{
	static	int	how = 0;

	use->alias[how][0] = tab[1];
	use->alias[how][1] = tab[2];
	how += 1;
}

void	print_aliaszer(char **tab)
{
	int	a = -1;

	while (tab[++a])
		printf("%s ", tab[a]);
	printf("\n");
}

void	print_alias(char ***tab)
{
	int	a = -1;
	int	b = -1;

	if (tab[0] == NULL)
		return;
	while (tab[++a]) {
		print_aliaszer(tab[a]);
	}
}

void	alias_func(char **tab, use_value *use)
{
	static	int	b = 0;
	int	size = 0;

	size = alias_lenght(tab);
	if (size == 1)
		print_alias(use->alias);
	else if (size > 3)
		return;
	else if (tab[2] == NULL)
		use->exit = 1;
	else {
//		if (is_alpha(tab[1]) == -1 || is_alpha(tab[2]) == -1)
//			use->exit = 1;
//		else {
			malloc_alias(tab, use);
			put_in_alias(tab , use);
//		}
	}
	b += 1;
}
