/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** Alias
*/

#include "../../include/my_sh.h"

char	**replace_alias(char **tab, t_mini *mini)
{
	int	a = -1;
	int	b = -1;

	if (mini->alias == NULL)
		return (tab);
	while (tab[++a]) {
		while (mini->alias[++b] && mini->alias[b][0]) {
			if ((strcmp(tab[a], mini->alias[b][0]) == 0))
				tab[a] = strdup(mini->alias[b][1]);
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

void	malloc_alias(char **tab, t_mini *mini)
{
	static	int	how = 0;

	how == 0 ? (mini->alias = malloc(sizeof(char **) * 40)) : 0;
	mini->alias[0] == NULL ? how = 0 : 0;
	mini->alias[how] = malloc(sizeof(char *) * 3);
	mini->alias[how][0] = malloc(sizeof(char) * strlen(tab[1]) + 3);
	mini->alias[how][1] = malloc(sizeof(char) * strlen(tab[2]) + 3);
	mini->alias[how][2] = NULL;
	how += 1;
	mini->alias[how] = NULL;
}

void	put_in_alias(char **tab, t_mini *mini)
{
	static	int	how = 0;

	mini->alias[how][0] = tab[1];
	mini->alias[how][1] = tab[2];
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

	if (tab[0] == NULL)
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
	else if (size > 3)
		return (0);
	else {
		malloc_alias(tab, mini);
		put_in_alias(tab, mini);
	}
	b += 1;
	return (0);
}
