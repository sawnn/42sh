/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** PWD and ENV
*/

#include "../../include/my_sh.h"

int	my_exit(t_mini *mini, NOU node **head)
{
	if (mini->exit[1] == NULL)
		exit(mini->global);
	else if (my_getnbr(mini->exit[1]) == 86 ||
		length_tab(mini->exit) > 2) {
		write(2, "exit: Expression Syntax.\n", 25);
		return (86);
	}
	else
		exit(my_getnbr(mini->exit[1]));
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
