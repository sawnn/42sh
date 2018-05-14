/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** path
*/

#include "../include/my_minishell.h"

int	is_bin(t_mini *mini)
{
	if (access(mini->tab[0], F_OK) == 0) {
		mini->rpath = mini->tab[0];
		return (0);
	}
	return (1);
}

void	call_argument(t_mini *mini, node **head)
{
	int	stdin = dup(0);
	int	stdout = dup(1);

	mini->cmd = pre_call_pipe(mini);
	if (is_redirection(mini) == 1)
		return;
	if (check_built(mini, head) >= 0);
	else if (check_path(mini, head, 0) == 0) {
		mini->head = head;
		mini->global = which_exec(mini);
	}
	else if (mini->b_exit != 1) {
		put_msg(2, mini->tab[0]);
		put_msg(2, ": Command not found.\n");
		mini->global = 1;
		mini->b_exit = 0;
	}
	dup2(stdin, 0);
	dup2(stdout, 1);
}

int	buff_null(t_mini *mini)
{
	if (isatty(0) == 1)
		write(1, "exit\n", 5);
	return (mini->global);
}

void	is_error_exit(t_mini *mini)
{
	mini->b_exit = 1;
	mini->global = 1;
}
