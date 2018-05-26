/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** path
*/

#include "../../include/my_sh.h"

int	check_remove_path_bis(t_mini *mini, char *path3)
{
	if (access(path3, F_OK) == 0) {
		mini->rpath = path3;
		return (0);
	}
	if (access(mini->tab[0], F_OK) == 0) {
		mini->rpath = mini->tab[0];
		return (0);
	}
	return (-1);
}

int	check_remove_path(t_mini *mini)
{
	char	*path = my_strcat("/usr/local/bin/", mini->tab[0]);
	char	*path2 = my_strcat("/usr/bin/", mini->tab[0]);
	char	*path3 = my_strcat("/bin/", mini->tab[0]);

	if (access(path, F_OK) == 0) {
		mini->rpath = path;
		return (0);
	}
	if (access(path2, F_OK) == 0) {
		mini->rpath = path2;
		return (0);
	}
	return (check_remove_path_bis(mini, path3));
}

int	is_path(t_mini *mini, node *tmp, int i)
{
	mini->str = tmp->str;
	tmp->str = skip_char(tmp->str, 5);
	mini->path = my_str_to_word_tab_sep(tmp->str, ':');
	tmp->str = mini->str;
	mini->j = i;
	i = 0;
	if (is_bin(mini) == 0)
		return (0);
	while (mini->path[i] != NULL) {
	mini->patht = my_strcat(mini->path[i], "/");
		mini->patht = my_strcat(mini->patht, mini->tab[0]);
		if (access(mini->patht, F_OK) == 0) {
			mini->rpath = mini->patht;
			mini->env[mini->j] = mini->str;
			return (0);
		}
		i = i + 1;
	}
	mini->env[mini->j] = mini->str;
	return (-1);
}

int	check_path(t_mini *mini, node **head, int no_path)
{
	int	i = 0;
	node	*tmp = (*head);

	if (tmp == NULL) {
		my_env(mini, head);
		tmp = (*head);
	}
	while (tmp != NULL) {
		if (my_strncmp(tmp->str, "PATH=", 5) == 0) {
			no_path = 1;
			break;
		}
		i = i + 1;
		tmp = tmp->next;
	}
	if (no_path == 0)
		return (check_remove_path(mini));
	if (no_path == 1 && (my_strcmp(tmp->str, "PATH=") == 0))
		return (-1);
	return (is_path(mini, tmp, i));
}

int	which_exec(t_mini *mini)
{
	//if (!mini->cmd)
	//	return (mini->global);
	//else if (mini->cmd[1] == NULL)
	my_exec(mini);
	//else
	//	my_exec_pipe(mini, mini->cmd);
	return (mini->global);
}

