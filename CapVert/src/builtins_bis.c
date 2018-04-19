/*
** EPITECH PROJECT, 2018
** uti
** File description:
** uti
*/

#include "../include/my_minishell.h"

void	my_unsetenv(t_mini *mini, node **head)
{
	node	*tmp = (*head);
	char	*s2;
	int	i = 1;
	int	j = 1;

	while (mini->tab[j] != NULL) {
		s2 = my_strcat(mini->tab[j], "=");
		while (tmp != NULL) {
			if (my_strncmp(tmp->str, s2, my_strlen(s2)) == 0)
				delete_node(head, i);
			else
				i = i + 1;
			tmp = tmp->next;
		}
		i = 1;
		j = j + 1;
		tmp = (*head);
	}
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
