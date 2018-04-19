/*
** EPITECH PROJECT, 2018
** builtins
** File description:
** builtins
*/

#include "../include/my.h"
#include "../include/shell.h"

void	builtins_env(t_value *sh, char **env, int *checky, int *path)
{
	if (my_strcmp("cd", sh->arg[0]) == 0) {
		*path = 1;
		cd(sh->arg, env, checky, sh);
	}
	if (my_strcmp("env", sh->arg[0]) == 0) {
		*path = 1;
		reset_env(sh->str);
		print_list(sh->env);
		sh->str = search_env(env, "PATH=");
	}
	if (my_strcmp("setenv", sh->arg[0]) == 0) {
		*path = 1;
		reset_env(sh->str);
		my_setenv(sh, sh->arg);
		sh->str = search_env(env, "PATH=");
	}
}

int	builtins_exit(t_value *sh, char **env, int *path)
{
	if (my_strcmp("unsetenv", sh->arg[0]) == 0) {
		*path = 1;
		reset_env(sh->str);
		my_unsetenv(sh, sh->arg);
		sh->str = search_env(env, "PATH=");
	}
	if (my_strcmp("exit", sh->arg[0]) == 0) {
		isatty(0) ? my_printf("exit\n") : 0;
		return (0);
	}
	if (*path != 1)
		move_env(sh, env);
	*path = 0;
	return (1);
}
