/*
** EPITECH PROJECT, 2018
** error
** File description:
** error
*/

#include "../include/my.h"
#include "../include/shell.h"
#include <sys/wait.h>
#include <errno.h>

void	my_prompt(char *str)
{
	write(0, str, my_strlen(str));
}

void	catch_c(int sign)
{
	if (sign == SIGINT)
		my_printf("\n\033[1m\033[32m➜  \033[36mValentin.D\033[0m ");
}

void	permission_denied(t_value *sh, char **env)
{
	if ((execve(sh->command[0], sh->arg, env)) == -1) {
		if (errno == EACCES) {
			write(2, sh->command[0], my_strlen(sh->command[0]));
			write(2, ": Permission denied.\n", 21);
			sh->exit = 1;
			exit(1);
		}
		if (errno == ENOEXEC) {
			write(2, sh->command[0], my_strlen(sh->command[0]));
			write(2, ": Exec format error. Wrong Architecture.\n",
				41);
			sh->exit = 1;
			exit(1);
		}
	}
}

void	error(t_value *sh)
{
	waitpid(sh->child_pid, &sh->status, 0);
	if (sh->status == 256)
		sh->exit = 1;
	if (WTERMSIG(sh->status) == 11) {
		write(2, "Segmentation fault", 18);
		if (WCOREDUMP(sh->status))
			write(2, " (core dumped)", 14);
		write(2, "\n", 1);
		sh->exit = 139;
	}
	if (WTERMSIG(sh->status) == 8) {
		write(2, "Floating exception", 18);
		if (WCOREDUMP(sh->status))
			write(2, " (core dumped)", 14);
		write(2, "\n", 1);
		sh->exit = 136;
	}
}
