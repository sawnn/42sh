/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** Paths
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

void	path_error(use_value *use, char **env)
{
	if (errno == EACCES) {
		my_puterror(use->arg[0]);
		my_puterror(": Permission denied.\n");
		exit(1);
	}
	if (errno == ENOEXEC) {
		my_puterror(use->arg[0]);
		my_puterror(": Exec format error. Wrong Architecture.\n");
		exit(1);
	}
}

void	direct_path(use_value *use, char **env)
{
	use->pid = fork();
	if (use->pid == 0) {
		redirections(use);
		if ((execve(use->arg[0], use->arg, env)) == -1)
			path_error(use, env);
	}
}

void	indirect_path(use_value *use, char **env)
{
	while (use->path[use->clms])
		use->clms = use->clms + 1;
	while ((access(use->t_path, F_OK) != 0) && (use->a <= use->clms - 1)) {
		use->t_path = my_strcat(use->path[use->a],
					my_strcat("/", use->arg[0]));
		use->a = use->a + 1;
	}
	use->clms = 0; use->a = 0;
	if (access(use->t_path, F_OK) == 0) {
		use->pid = fork();
		if (use->pid == 0) {
			redirections(use);
			execve(use->t_path, use->arg, env);
		}
		wait(&use->status);
		use->status == 512 ? use->exit = 1 : 0;
	} else {
		my_printf("%s: Command not found.\n", use->arg[0]);
		use->exit = 1;
	}
	my_memset(use->t_path, 0, my_strlen(use->t_path));
}
