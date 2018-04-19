/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my_minishell.h"
#define	CMP my_strcmp(str, mini->tab[i + 1])

void	put_msg(int i, char *str)
{
	write(i, str, my_strlen(str));
}

int	simple_redir_left(t_mini *mini, int i)
{
	char	*pathname = mini->tab[i + 1];
	int	fd = open(pathname, 0666);

	if (fd == -1) {
		my_printf("%s: No such file or directory2.\n", mini->tab[i + 1]);
		return (mini->global = 1);
	}
	if (dup2(fd, 0) == -1) {
		my_printf("%s: No such file or directory3.\n", mini->tab[i + 1]);
		return (mini->global = 1);
	}
	close(fd);
	mini->tab[i] = NULL;
	return (mini->global = 0);
}

int	double_redir_left(t_mini *mini, int i)
{
	char	*pathname = ".ok";
	int	fd = open(pathname, O_CREAT | O_WRONLY | O_TRUNC, 0666);

	while (1) {
		write(1, "? ", 2);
		char *str = get_next_line(0);
		if (!str) {
			mini->tab[i] = "<";
			mini->tab[i + 1] = ".ok";
			return (simple_redir_left(mini, i));
		}
		CMP != 0 ? write(fd, str, my_strlen(str)) : 0;
		CMP != 0 ? write(fd, "\n", 1) : 0;
		if (my_strcmp(str, mini->tab[i + 1]) == 0) {
			mini->tab[i] = "<";
			mini->tab[i + 1] = ".ok";
			return (simple_redir_left(mini, i));
		}
	}
}
