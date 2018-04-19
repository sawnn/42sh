/*
** EPITECH PROJECT, 2018
** uti
** File description:
** uti
*/

#include "../include/my_minishell.h"

void	my_env(t_mini *mini, node **head)
{
	int	i = 0;

	while (mini->env[i] != NULL) {
		(*head) = add_link((*head), mini->env[i]);
		i = i + 1;
	}
}

void	add_setenv(t_mini *mini, node **head)
{
	if (mini->tab[2] == NULL)
		(*head) = add_link((*head), my_strcat(mini->tab[1], "="));
	else {
		char	*s2 = my_strcat(mini->tab[1], "=");
		(*head) = add_link((*head), my_strcat(s2, mini->tab[2]));
	}
}

void	replace_setenv(t_mini *mini, node *tmp)
{
	if (mini->tab[2] == NULL)
		tmp->str = my_strcat(mini->tab[1], "=");
	else {
		char	*s2 = my_strcat(mini->tab[1], "=");
		tmp->str = my_strcat(s2, mini->tab[2]);
	}
}

void	my_setenv(t_mini *mini, node **head)
{
	node	*tmp = (*head);
	char	*s2 = my_strcat(mini->tab[1], "=");
	int	i = 0;
	int	j = 0;

	while (tmp != NULL) {
		if (my_strncmp(tmp->str, s2, my_strlen(s2)) == 0 && j != 1) {
			replace_setenv(mini, tmp);
			j = 1;
		}
		tmp = tmp->next;
		i = i + 1;
	}
	if (j == 0)
		add_setenv(mini, head);
}

int	check_built(t_mini *mini, node **head)
{
	save_env(mini, head);
	if (my_strcmp(mini->tab[0], "env") == 0)
		return (my_call_env(mini, head));
	else if (my_strcmp(mini->tab[0], "setenv") == 0)
		return (my_call_setenv(mini, head));
	else {
		if (my_strcmp(mini->tab[0], "unsetenv") == 0)
			return (my_call_unsetenv(mini, head));
		else if (my_strcmp(mini->tab[0], "cd") == 0)
			return (my_call_cd(mini, head));
	}
	mini->global = -1;
	return (mini->global);
}
