/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** Alias
*/

#include "../../include/my_sh.h"

void	malloc_alias(char **tab, t_mini *mini)
{
	static	int	how = 0;
	int	size = size_tab(tab);
	int	a = 0;
	int	c = 1;

	how == 0 ? (mini->alias = malloc(sizeof(char **) * 100)) : 0;
	mini->alias[how] = malloc(sizeof(char *) * size + 1);
	while (tab[c] && ++a != size) {
		mini->alias[how][a] = malloc(sizeof(char) * strlen(tab[c]) + 3);
		c += 1;
	}
	mini->alias[how][a] = NULL;
	how += 1;
	mini->alias[how] = NULL;
}

void	put_in_alias(char **tab, t_mini *mini)
{
	static	int	how = 0;
	int	size = size_tab(tab)-1;
	int	a = -1;
	int	c = 1;

	while (++a != size) {
		mini->alias[how][a] = strdup(mini->b_ali[c]);
		c += 1;
	}
	how += 1;
}

void	print_aliaszer(char **tab)
{
	int	a = -1;

	if (!tab)
		return;
	while (tab[++a]) {
		if (a != 0)
			printf(" ");
		printf("%s", tab[a]);
	}
	printf("\n");
}

void	print_alias(char ***tab)
{
	int	a = -1;

	if (!tab)
		return;
	while (tab[++a]) {
		print_aliaszer(tab[a]);
	}
}

int	alias_func(t_mini *mini, NOU node **head)
{
	char	**tab = mini->tab;
	static	int	b = 0;
	int	size = 0;

	size = alias_lenght(tab);
	if (size == 1)
		print_alias(mini->alias);
	else if(!tab[2])
		return (0);
	else {
		malloc_alias(tab, mini);
		put_in_alias(tab, mini);
	}
	b += 1;
	return (0);
}
