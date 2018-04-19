/*
** EPITECH PROJECT, 2018
** env
** File description:
** .c
*/

#include "../include/my.h"
#include "../include/shell.h"
#include <sys/wait.h>

void	go_to_pipe(t_value *sh, char **env)
{
	int nb = 0;

	if ((nb = count_pipe(sh->arg, sh)) == -1)
		return;
	else if (nb > 1) {
		triple_tab(sh->arg, nb, sh, env);
		return;
	}
	sh->child_pid = fork();
	if (sh->child_pid == 0) {
		reset_env(sh->str);
		if (pars_command(sh) == 0)
			return;
		execve(sh->strcat, sh->arg, env);
	}
	sh->i = 0;
	wait(&sh->status);
	wait(&sh->status);
}
