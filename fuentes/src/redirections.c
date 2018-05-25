/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** Redirections
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

void	write_to_file(use_value *use, int a)
{
	int	fd = open(use->arg[a+1], 577, 432);

	dup2(fd, 1);
	close(fd);
}

void	add_to_file(use_value *use, int a)
{
	int	fd = open(use->arg[a+1], 1089, 432);

	dup2(fd, 1);
	close(fd);
}

void	stock_in_file(use_value *use, int a)
{
	int	fd = open(use->arg[a+1], O_RDONLY);

	if (fd == -1) {
		my_puterror(use->arg[a+1]);
		my_puterror(": No such file or directory.\n");
		exit(1);
	}
	dup2(fd, 0);
	close(fd);
}

void	heja_in_file(use_value *use, int a)
{
	int	fd = open(".heja", 577, 432);
	char	*t;

	my_printf("? ");
	while ((t = get_next_line(0)) && (my_strcmp(use->arg[a+1], t) != 0)) {
		my_printf("? ");
		write(fd, t, my_strlen(t));
		write(fd, "\n", 1);
	}
	use->arg[a] = "<";
	use->arg[a + 1] = ".heja";
	stock_in_file(use, a);
	close(fd);
}

void	redirections(use_value *use)
{
	int	a = -1;
	int	b = 0;

	while (use->arg[++a]) {
		if (my_strcmp(use->arg[a], ">") == 0) {
			write_to_file(use, a); use->arg[a + 1] = NULL; b = 1; }
		if (my_strcmp(use->arg[a], ">>") == 0) {
			add_to_file(use, a); use->arg[a + 1] = NULL; b = 1; }
		if (my_strcmp(use->arg[a], "<") == 0) {
			stock_in_file(use, a); use->arg[a + 1] = NULL; b = 1; }
		if (my_strcmp(use->arg[a], "<<") == 0) {
			heja_in_file(use, a); use->arg[a + 1] = NULL; b = 1; }
	}
	b == 1 ? (use->arg[a - 1] = NULL): 0;
	return;
}
