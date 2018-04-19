/*
** EPITECH PROJECT, 2018
** redirections
** File description:
** gaspacho andalou
*/

#include "my.h"

void	simple_right(UNU t_shell *shell, char *str)
{
	int	fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0666);

	dup2(fd, 1);
}

void	simple_left(UNU t_shell *shell, char *str)
{
	int	fd = open(str, O_RDONLY);

	if (fd == -1) {
		if (errno == EACCES) {
			write(1, shell->tab[2], my_strlen(shell->tab[2]));
			write(1, ": Permission denied.\n", 22);
			call_exit(1);
		}
		else {
			write(1, shell->tab[2], my_strlen(shell->tab[2]));
			write(1, ": No such file or directory.\n", 29);
			call_exit(1);
		}
		return;
	}
	dup2(fd, 0);
}

void	double_right(UNU t_shell *shell, char *str)
{
	int	fd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0666);

	dup2(fd, 1);
}

void	double_left(t_shell *shell, char *str)
{
	char	*input = "";
	int	a = 0;
	int	fd = open(".lol", O_CREAT | O_WRONLY | O_TRUNC, 0666);

	while (a == 0) {
		if (!input)
			return;
		write(1, "? ", 2);
		input = get_next_line(0);
		if (input && my_strcmp(str, input) == 84) {
			write(fd, input, my_strlen(input));
			write(fd, "\n", 1);
		}
		if (!input || my_strcmp(input, str) == 0) {
			shell->tab[shell->glob + 1 - 1] = "<";
			shell->tab[shell->glob + 1] = ".lol";
			simple_left(shell, shell->tab[shell->glob + 1]);
			a = 1;
		}
	}
}
