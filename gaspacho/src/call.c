/*
** EPITECH PROJECT, 2018
** call
** File description:
** gaspacho andalou
*/

#include "my.h"

int	call_exit(int nb)
{
	static int	i = 0;

	if (nb != -1)
		i = nb;
	return (i);
}

int	keep_path(int nb)
{
	static int	i = 0;

	if (nb != -1)
		i = nb;
	return (i);
}

int	call_fd(int nb)
{
	static int	i = -5;

	if (nb != -1)
		i = nb;
	return (i);
}

void	call_builtin(int i, t_shell *shell)
{
	void	(*fptr[6])(char *, t_list **);

	fptr[0] = &print_env;
	fptr[1] = &my_setenv;
	fptr[2] = &my_unsetenv;
	fptr[3] = &my_cd;
	fptr[4] = &my_exit;
	fptr[5] = NULL;
	(*fptr[i])(shell->input, &shell->my_env);
}
