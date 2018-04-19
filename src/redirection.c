/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** redeirect
*/

#include "../include/my_minishell.h"

int	check_argum(t_mini *mini)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;

	while (mini->tab[i] != NULL) {
		if (my_strcmp(mini->tab[i], ">") == 0)
			j = j + 1;
		if (my_strcmp(mini->tab[i], ">>") == 0)
			k = k + 1;
		i = i + 1;
	}
	mini->global = ((j > 1 || k > 1) ? 84 : 0);
	j > 1 || k > 1 ? write(2, "Ambiguous output redirect.\n", 27) : 0;
	return (mini->global);
}

int	simple_redirection(t_mini *mini, int i)
{
	char	*pathname = mini->tab[i + 1];
	int	fd = open(pathname, O_TRUNC | FLAGS_OPEN | FLAGS_OPEN_BIS);

	if (fd == -1) {
		write(2, "Error: open!\n", 13);
		return (mini->global = 84);
	}
	if (dup2(fd, 1) == -1) {
		write(2, "Error: dup2!\n", 13);
		return (mini->global = 84);
	}
	close(fd);
	mini->tab[i] = NULL;
	return (mini->global = 0);
}

int	double_redirection(t_mini *mini, int i)
{
	char	*pathname = mini->tab[i + 1];
	int	fd = open(pathname, O_APPEND | FLAGS_OPEN | FLAGS_OPEN_BIS);

	if (fd == -1) {
		write(2, "Error: open!\n", 13);
		return (mini->global = 84);
	}
	if (dup2(fd, 1) == -1) {
		write(2, "Error: dup2!\n", 13);
		return (mini->global = 84);
	}
	close(fd);
	mini->tab[i] = NULL;
	return (mini->global = 0);
}

int	is_redirection(t_mini *mini)
{
	int	i = 0;

	if (check_argum(mini) == 84)
		return (84);
	while (mini->tab[i] != NULL) {
		if (my_strcmp(mini->tab[i], ">") == 0) {
			return (simple_redirection(mini, i));
		}
		if (my_strcmp(mini->tab[i], ">>") == 0) {
			return (double_redirection(mini, i));
		}
		if (my_strcmp(mini->tab[i], "<") == 0) {
			return (simple_redir_left(mini, i));
		}
		if (my_strcmp(mini->tab[i], "<<") == 0) {
			return (double_redir_left(mini, i));
		}
		i = i + 1;
	}
	return (2);
}
