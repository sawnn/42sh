/*
** EPITECH PROJECT, 2018
** env utils
** File description:
** gaspacho andalou
*/

#include "my.h"

void	setenv_new_node(char **tab, t_list **tmp, t_list **my_env, t_list *save)
{
	t_list	*elem = NULL;
	char	*str = NULL;

	if ((elem = malloc(sizeof(t_list))) == NULL)
		return;
	str = my_strcat(tab[1], "=");
	tab[2] ? str = my_strcat(str, tab[2]) : 0;
	(*tmp)->next = elem;
	elem->str = str;
	elem->next = NULL;
	(*tmp)->str = elem->str;
	*my_env = *tmp;
	*my_env = save;
}

void	setenv_exist(char **tab, t_list *tmp, t_list ** my_env, t_list *save)
{
	char	*str = NULL;

	str = my_strcat(tab[1], "=");
	tab[2] ? str = my_strcat(str, tab[2]) : 0;
	*my_env = tmp;
	(*my_env)->str = str;
	*my_env = save;
}

t_list	*fill_env(char **env, t_shell *shell)
{
	t_list	*tmp = NULL;
	int	i = -1;

	if ((tmp = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (env[0] == NULL) {
		tmp = add_node(tmp, "PATH=/usr/local/bin:/usr/bin:/bin");
		if ((shell->env = malloc(sizeof(char *) * 1)) == NULL)
			return (NULL);
		shell->env[0] = "PATH=/usr/local/bin:/usr/bin:/bin";
		return (tmp);
	}
	while (env[++i] != NULL);
	while (--i >= 0)
		tmp = add_node(tmp, env[i]);
	return (tmp);
}

char	*get_from_env(t_list *list, char *var)
{
	int	i = -1;
	t_list	*tmp = list;
	char	*str = NULL;

	while (tmp->next) {
		if (my_strncmp(var, tmp->str, my_strlen(var)) == 0)
			str = tmp->str;
		tmp = tmp->next;
	}
	while (str[++i] != '\0')
		if (str[i] == '=')
			return (str + i + 1);
	return (NULL);
}
