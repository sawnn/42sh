/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** call
*/

#include "../../include/my_sh.h"

int	call_builtins(int i, t_mini *mini, node **head)
{
	int	(*fptr[6])(t_mini *, node **);
	int	ret = 0;

	fptr[0] = my_call_env;
	fptr[1] = my_call_setenv;
	fptr[2] = my_call_unsetenv;
	fptr[3] = my_call_cd;
	fptr[4] = my_exit;
	fptr[5] = NULL;
	ret = (*fptr[i])(mini, head);

	if (i == 4 && ret == 86) {
		is_error_exit(mini);
	}
	else {
		isatty(0) == 1 ? write(1, "exit\n", 5) : 0;
		return (my_exit(mini, head));
	}
	return (ret);
}

int	is_builtins(t_mini *mini, node **head)
{
	char	*built[6] = {"env", "setenv", "unsetenv", "cd", "exit", NULL};
	int	i = 0;

	while (built[i] != NULL) {
		if (my_strcmp(mini->tab[0], built[i]) == 0)
			return (call_builtins(i, mini, head));
		i += 1;
	}
	return (mini->global = -1);
}