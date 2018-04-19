/*
** EPITECH PROJECT, 2018
** path
** File description:
** gaspacho andalou
*/

#include "my.h"

char	*get_path(char *str, char *input)
{
	char	**tab = my_str_to_wordtab(str, ':');
	char	**prompt = my_str_to_wordtab(input, ' ');
	int	i = -1;
	char	*tmp = NULL;

	while (tab[++i] != NULL) {
		tmp = my_strcat(my_strcat(tab[i], "/"), prompt[0]);
		if (access(tmp, F_OK) != -1) {
			free(prompt);
			free(tmp);
			return (tab[i]);
		}
	}
	free(prompt);
	free(tmp);
	return (str);
}

char	*find_path(t_shell *shell, int nb)
{
	int	i = -1;
	t_list	*tmp = shell->my_env;

	while (nb == 0 && shell->env[++i] != NULL) {
		if (my_strncmp(shell->env[i], "PATH=", 4) == 0) {
			return (get_path(&shell->env[i][6], shell->input));
		}
	}
	while (nb == 1 && tmp) {
		if (my_strncmp(tmp->str, "PATH=", 4) == 0) {
			return (get_path(&tmp->str[6], shell->input));
		}
		tmp = tmp->next;
	}
	return (NULL);
}
