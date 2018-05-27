/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** call
*/

#include "../../include/my_sh.h"

int	call_builtins(int i, t_mini *mini, node **head)
{
	int	(*fptr[13])(t_mini *, node **); int	ret = 0;
	fptr[0] = my_call_env;
	fptr[1] = my_call_setenv;
	fptr[2] = my_call_unsetenv;
	fptr[3] = my_call_cd;
	fptr[4] = my_exit;
	fptr[5] = call_set;
	fptr[6] = my_echo;
	fptr[7] = alias_func;
	fptr[8] = my_which;
	fptr[9] = my_where;
	fptr[10] = repeat;
	fptr[11] = call_if;
	fptr[12] = NULL;
	ret = (*fptr[i])(mini, head);
	if (i == 4 && ret == 86) {
		is_error_exit(mini);
	} else if (i == 4) {
		return (my_exit(mini, head));
	} return (ret);
}

int	is_builtins(t_mini *mini, node **head)
{
	char	*built[13] = {"env", "setenv", "unsetenv", "cd",
	"exit", "set", "echo", "alias", "which", "where", "repeat", "if", NULL};
	int	i = 0;

	while (built[i] != NULL) {
		if (my_strcmp(mini->tab[0], built[i]) == 0)
			return (call_builtins(i, mini, head));
		i += 1;
	}
	return (mini->global = -1);
}
