/*
** EPITECH PROJECT, 2018
** main
** File description:
** gaspacho andalou
*/

#include "my.h"

int	find_command(t_shell *shell)
{
	char	**tab = tab_command();
	int	i = -1;
	int	a = 0;
	int	stdin = dup(0);
	int	stdout = dup(1);
	shell->path = find_path(shell, 0);
	keep_path(-1) == 2 ? shell->path = find_path(shell, 1) : 0;
	shell->path ? shell->path = my_strcat("/", shell->path) : 0;
	if (redirections(shell) == 1)
		if (call_exit(-1) == 1)
			a = 1;
	while (tab[++i] != NULL)
		if (my_strcmp(shell->tab[0],  tab[i]) == 0) {
			call_builtin(i, shell);
			a = 1;
		}
	a == 0 ? call_command(shell) : 0;
	dup2(stdin, 0);
	dup2(stdout, 1);
	return (1);
}

int	ctrl_d(char *prompt)
{
	if (prompt == NULL) {
		isatty(0) == 1 ? my_putstr("exit\n") : 0;
		return (call_exit(-1));
	}
	return (-5);
}

int	main(UNU int ac, UNU char **av, char **env)
{
	t_shell	*shell = NULL;
	int	a = 0;

	if ((shell = malloc(sizeof(t_shell))) == NULL)
		return (84);
	signal(SIGINT, SIG_IGN);
	shell->glob = 0;
	shell->env = env;
	shell->my_env = fill_env(env, shell);
	while ("gaspacho andalou") {
		write(0, "\x1b[31mGaspacho andalou-$>\x1b[0m", 29);
		shell->input = get_next_line(0);
		if ((a = ctrl_d(shell->input)) != -5)
			return (a);
		shell->input = my_epure_str(shell->input);
		if (shell->input[0] != '\0')
			handle_input(shell);
		free(shell->input);
	}
	return (0);
}
