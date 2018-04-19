/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** PWD and ENV
*/

#include "../include/my_minishell.h"

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

int	save_env(t_mini *mini, node **head)
{
	node	*tmp = (*head);

	if (tmp == NULL) {
		my_env(mini, head);
		tmp = (*head);
	}
	while (tmp != NULL) {
		if (my_strncmp(tmp->str, "HOME=", my_strlen("HOME=")) == 0) {
			mini->savehome = skip_char(tmp->str, 5);
			break;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	replace_pwd(char *pwd, node **head)
{
	node	*tmp = (*head);

	while (tmp != NULL) {
		if (my_strncmp(tmp->str, "PWD=", my_strlen("PWD=")) == 0) {
			pwd = my_strcat("PWD=", pwd);
			tmp->str = pwd;
			return (0);
		}
		tmp = tmp->next;
	}
	return (-1);
}

int	replace_oldpwd(char *oldpwd, node **head)
{
	node	*tmp = (*head);

	while (tmp != NULL) {
		if (my_strncmp(tmp->str, "OLDPWD=", 7) == 0) {
			oldpwd = my_strcat("OLDPWD=", oldpwd);
			tmp->str = oldpwd;
			return (0);
		}
		tmp = tmp->next;
	}
	return (-1);
}
