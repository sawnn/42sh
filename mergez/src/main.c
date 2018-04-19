/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void	use_env(t_value *sh, char **env)
{
	sh->strcat = my_strcat(sh->path[sh->i], my_strcat("/", sh->command[0]));
	if (access(sh->strcat, F_OK) == 0)
		go_to_pipe(sh, env);
	else {
		sh->i = 0;
		sh->exit = 1;
		my_printf("%s: Command not found.\n", sh->command[0]);
	}
}

void	move_env(t_value *sh, char **env)
{
	if (access(sh->command[0], F_OK) == 0) {
		sh->child_pid = fork();
		if (sh->child_pid == 0) {
			if (pars_command(sh) == 0)
				return;
			permission_denied(sh, env);
		}
		error(sh);
	}
	else {
		sh->strcat = my_strcat(sh->path[sh->i],
					my_strcat("/", sh->command[0]));
		while (access(sh->strcat, F_OK) == -1 &&
			sh->i < (count_path(sh->path) - 1)) {
			sh->i = sh->i + 1;
			sh->strcat = my_strcat(sh->path[sh->i],
						my_strcat("/", sh->command[0]));
		}
		use_env(sh, env);
	}
}

int	my_shell(t_value *sh, char **env, int *checky, int *path)
{
	sh->command = my_str_to_wordtab(sh->tmp, ' ');
	sh->arg = my_str_to_wordtab(sh->tmp, ' ');
	sh->path = my_str_to_wordtab(sh->str, ' ');
	if (sh->arg[0] == NULL) {
		my_prompt("\033[1m\033[32m➜  \033[36mValentin.D\033[0m ");
		sh->check = 1;
	}
	else {
		sh->check = 0;
		builtins_env(sh, env, checky, path);
		if (builtins_exit(sh, env, path) == 0)
			return (0);
	}
	if (sh->check != 1 && sh->prompt == 0) {
		sh->check = 0;
		*path = 0;
		my_prompt("\033[1m\033[32m➜  \033[36mValentin.D\033[0m ");
	}
	return (1);
}

int	main_bis(char **env, t_value *sh, int i)
{
	if (env[0] == NULL)
		return (1);
	sh->env = NULL;
	while (env[++i])
		sh->env = add_link(sh->env, env[i]);
	if ((sh->str = search_env(env, "PATH=")) == NULL)
		return (1);
	sh->i = 0;
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_value sh;
	int	i = -1;
	int checky = 1;
	int path = 0;

	if (main_bis(env, &sh, i) == 1)
		return (1);
	my_prompt("\033[1m\033[32m➜  \033[36mValentin.D\033[0m ");
	signal(SIGINT, catch_c);
	while ((sh.tmp = get_next_line (0))) {
		sh.exit = 0;
		sh.prompt = 0;
		if (nb_semicolons(&sh) > 0) {
			if (check_semicolons(&sh, env, &checky, &path) == 0)
				return (sh.exit);
		}
		else if (my_shell(&sh, env, &checky, &path) == 0)
			return (sh.exit);
	}
	isatty (0) ? my_printf("exit\n") : 0;
	return (sh.exit);
}
