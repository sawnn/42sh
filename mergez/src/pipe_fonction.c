/*
** EPITECH PROJECT, 2018
** pipe_fonction
** File description:
** .c
*/

#include "../include/my.h"
#include "../include/shell.h"
#include <sys/wait.h>

void	pipe_fonction(char ***tab, t_value *sh, char **env)
{
	int pipefd[2]; pid_t pid; int fd_in = 0;
	int in = dup(0); int out = dup(1); int	ret = 0;
	while (*tab) {
		pipe(pipefd);
		if((pid = fork()) == -1)
			return;
		else if (pid == 0) {
			dup2(fd_in, 0);
			if (*(tab + 1))
				dup2(pipefd[1], 1);
			close(pipefd[0]);
			execve(sh->strcat, *tab, env);
			return;
		}
		else
			close(pipefd[1]); fd_in = pipefd[0]; tab++;
		if (*tab)
			check_envi(sh, env, *tab[0]);
	}
	waitpid(pid, &ret, 0);
	dup2(in, 0); dup2(out, 1);
}
