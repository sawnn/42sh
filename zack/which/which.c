/*
** EPITECH PROJECT, 2018
** which
** File description:
** gaspacho andalou
*/

int	my_which(t_mini *mini, NOU node **head)
{
	int	i = -1;

	while (mini->alias[++i]) {
		if (strcmp(mini->tab[1], mini->alias[i][0]) == 0) {
			printf("%s is aliased to %s\n",
			mini->tab[1], mini->alias[i][1]);
			return (0);
		}
	}
	return (1);
}
