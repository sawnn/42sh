/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** pipe
*/

#include "../include/my_minishell.h"

int	compt_pipe(char **tab, NOU t_mini *mini)
{
	int	i = -1;
	int	nb = 0;

	while (tab[++i] != NULL) {
		if (my_strcmp(tab[i], "|") == 0) {
			nb += 1;
		}
	}
	return (nb + 1);
}

char	***pre_call_pipe(t_mini *mini)
{
	char	**tmp = mini->tab;
	char	***cmd = NULL;
	int	b = compt_pipe(tmp, mini);

	if (b == -1) {
		mini->global = 1;
		return (NULL);
	}
	if ((cmd = malloc(sizeof(char **) * b + sizeof(char **))) == NULL)
		return (NULL);
	cmd = return_cmd(tmp, cmd, b);
	return (cmd);
}

char	**copy_tab(char **tab, char **cmd)
{
	int	i = 0;

	while (tab[i] != NULL) {
		cmd[i] = tab[i];
		i = i + 1;
	}
	cmd[i] = NULL;
	return (cmd);
}

int	size_tab(char **tab)
{
	int	i = -1;

	while (tab[++i] != NULL);
	return (i);
}

char	***return_cmd(char **tmp, char ***cmd, int b)
{
	int	i = -1;
	int	a = 0;
	int	j = 0;

	while (tmp[++i] != NULL) {
		if (my_strcmp(tmp[i], "|") == 0) {
			tmp[i] = NULL;
			cmd[a] = malloc(sizeof(char *) * size_tab(&tmp[j]) + 8);
			cmd[a] = copy_tab(&tmp[j], cmd[a]);
			a += 1;
			j = i + 1;
		}
	}
	if (tmp[i - 1] != NULL) {
		cmd[a] = malloc(sizeof(char *) * size_tab(&tmp[j]) + 8);
		cmd[a] = copy_tab(&tmp[j], cmd[a]);
	}
	cmd[b] = NULL;
	return (cmd);
}
