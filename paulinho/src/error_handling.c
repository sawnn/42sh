/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** Seg Faults
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

void	sig(int signo)
{
	if (signo == SIGINT)
		if (isatty(0) == 1)
			my_printf("\n\033[1m\033[32m→ mini_shell: \033[0m");
}

int	check_signals(use_value *use)
{
	signal(SIGINT, sig);
}

void	error_handling(use_value *use)
{
	waitpid(use->pid, &use->status, 0);
	if (use->status == 256)
		use->exit = 1;
	else if (WTERMSIG(use->status) == 11) {
		my_puterror("Segmentation fault");
		use->exit = 139;
		if (WCOREDUMP(use->status))
			my_puterror(" (core dumped)");
		my_puterror("\n");
	}
	else if (WTERMSIG(use->status) == 8) {
		my_puterror("Floating exception");
		use->exit = 136;
		if (WCOREDUMP(use->status))
			my_puterror(" (core dumped)");
		my_puterror("\n");
	}
}
