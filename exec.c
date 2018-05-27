/*
** EPITECH PROJECT, 2018
** exec
** File description:
** a
*/

#include "../../include/my_sh.h"

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
