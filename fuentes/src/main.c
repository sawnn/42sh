/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** Main
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

int	main(int ac, char **av, char **env)
{
	use_value	use;
	s_list		*list = NULL;
	int		c = 0;
	int		exitzer = 0;

	check_signals(&use);
	list = get_env(env, list);
	use.alias = NULL;
	while (42) {
		(isatty(0) == 1) ?
			my_printf("\033[1m\033[32m→ mini_shell: \033[0m") : 0;
		exitzer = use.exit;
		init_values(&use, env);
		if (builtins_cond(&use, list, av, env) == 0) {
			((c == 0) && (use.exit == 0)) ? exitzer = 0 : 0;
			return (exitzer);
		}
		c ++;
	}
	return (1);
}
