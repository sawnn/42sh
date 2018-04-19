/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** exec
*/

#include "../include/my_minishell.h"

int	cut(int	*stdin, int *stdout, t_mini *mini)
{
	dup2((*stdin), 0);
	dup2((*stdout), 1);
	free(mini->tab);
	return (mini->global);
}

void	core_exec(t_mini *mini, char ***cmd)
{
	mini->tab = *cmd;
	check_path(mini, mini->head, 0);
	EXEC == -1 ? print_errno(mini) : 0;
}

int	my_exec_pipe(t_mini *mini, char ***cmd)
{
	int	p[2]; int	fd_in = 0; pid_t	pid = 0;
	int	ret = 0; int	stdin = dup(0); int	stdout = dup(1);

	while (*cmd != NULL) {
		pipe(p);
		(pid = fork()) == -1 ? exit(EXIT_FAILURE) : 0;
		if (pid == 0) {
			dup2(fd_in, 0);
			(*(cmd + 1)) != NULL ? dup2(p[1], 1) : 0;
			close(p[0]);
			core_exec(mini, cmd);
		}
		else {
			close(p[1]);
			fd_in = p[0];
			cmd++;
		}
	}
	check_error(pid, &ret, mini);
	return (cut(&stdin, &stdout, mini));
}

int	my_exec(t_mini *mini)
{
	pid_t	pid = fork();
	int	ret = 0;

	if (pid) {
		waitpid(pid, &ret, 0);
		mini->global = ret/256;
		print_segfault(ret, mini);
	}
	else {
		if (execve(mini->rpath, mini->tab, mini->env) == - 1)
			return (print_errno(mini));
	}
	return (mini->global);
}
