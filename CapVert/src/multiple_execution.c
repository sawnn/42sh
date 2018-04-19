/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my_minishell.h"

int	compt_point(char *str)
{
	int	i = -1;
	int	nb = 0;

	while (str[++i] != '\0') {
		if (str[i] == ';' && str[i + 1] != '\0')
			nb += 1;
	}
	return (nb + 1);
}

int	pre_call(t_mini *mini, node **head)
{
	char	*str = mini->buf;
	int	j = 0;

	if (which_call(mini, head, str, j) == 84)
		return (84);
	return (mini->global);
}

int	which_call(t_mini *mini, node **head, char *str, int j)
{
	int	b = compt_point(mini->buf);
	char	***t_tab = malloc(sizeof(char **) * b + sizeof(char **));
	int	i = -1;
	int	a = 0;

	if (!t_tab)
		return (84);
	while (str[++i] != '\0') {
		if (str[i] == ';') {
			str[i] = '\0';
			t_tab[a] = my_str_to_word_tab_sep(&str[j], ' ');
			a += 1;
			j = i + 1;
		}
	}
	if (str[i - 1] != '\0')
		t_tab[a] = my_str_to_word_tab_sep(&str[j], ' ');
	t_tab[b] = NULL;
	return (send_tab(t_tab, mini, head));
}

int	send_tab(char ***t_tab, t_mini *mini, node **head)
{
	int	a = 0;
	while (t_tab[a] != NULL) {
		mini->tab = t_tab[a];
		mini->tab[0] != NULL ? call_argument(mini, head) : 0;
		a += 1;
	}
	return (mini->global);
}
