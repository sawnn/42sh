/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** handle_error
*/

#include "../../include/my_sh.h"


void	check_error(pid_t pid, int *ret, t_mini *mini)
{
	waitpid(pid, ret, 0);
	mini->global = (*ret)/256;
	print_segfault((*ret), mini);
}

void	print_segfault(int ret, t_mini *mini)
{
	if (WTERMSIG(ret) == 11) {
		put_msg(2, "Segmentation fault");
		if (WCOREDUMP(ret))
			put_msg(2, " (core dumped)");
		write(2, "\n", 1);
		mini->global = 139;
	}
	if (WTERMSIG(ret) == 8) {
		put_msg(2, "Floating exception");
		if (WCOREDUMP(ret))
			put_msg(2, " (core dumped)");
		write(2, "\n", 1);
		mini->global = 136;
	}
}

int	print_errno(t_mini *mini)
{
	if (errno == EACCES) {
		write(2, mini->tab[0], my_strlen(mini->tab[0]));
		put_msg(2, ": Permission denied.\n");
		mini->global = 1;
	}
	if (errno == ENOEXEC) {
		write(2, mini->tab[0], my_strlen(mini->tab[0]));
		put_msg(2, ": Exec format error.");
		put_msg(2, " Wrong Architecture.\n");
		mini->global = 1;
	}
	return (mini->global);
}
