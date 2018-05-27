/*
1;5002;0c** EPITECH PROJECT, 2018
** 42sh
** File description:
** repeat
*/

#include "../../include/my_sh.h"

int	repeat(t_mini *mini, NOU node **head)
{
	int	size = size_tab(mini->tab);
	int	rept = 0;
	int	a = 1;
	int	c = 0;
	mini->repeat = malloc(sizeof(char *) * size + 1);

	if (size < 3) {
		write(2, "repeat: Too few arguments.\n", 27);
		mini->global = 1;
		return (mini->global);
	}
	if (is_num(mini->tab[1]) != 1) {
		write(2, "repeat: Badly formed number.\n", 30);
		mini->global = 1;
		return (mini->global);
	}
	rept = atoi(mini->tab[1]);
	while (mini->tab[++a]) {
		mini->repeat[c] = strdup(mini->tab[a]);
		c += 1;
	}
	mini->repeat[c] = NULL;
	mini->tab = mini->repeat;
	while (rept != 0) {
		mini->global = check_cmd(mini, head);
		rept -= 1;
	}
	return (mini->global);
}
