/*
** EPITECH PROJECT, 2018
** redirection
** File description:
** .c
*/

#include "../include/my.h"
#include "../include/shell.h"

int	che_ouv(t_value *sh, int i)
{
	int fd;

	if ((fd = open(sh->arg[i], O_RDONLY)) == -1) {
		my_printf("%s: No such file or directory.\n", sh->arg[i]);
		sh->exit = 1;
		exit (sh->exit);
	}
	dup2(fd, 0);
	close (fd);
	return (1);
}

int	che_db_ouv(t_value *sh, int i)
{
	int fd = open(".test",  O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR |
			S_IRGRP | S_IWGRP | S_IWUSR);
	char *str;
	my_printf("? ");
	str = get_next_line(0);
	while (str && my_strcmp(str, sh->arg[i]) != 0) {
		write(fd, str, my_strlen(str));
		write(fd, "\n", 1);
		my_printf("? ");
		str = get_next_line(0);
	}
	sh->arg[i - 1] = "<";
	sh->arg[i] = ".test";
	pars_command(sh);
	return (1);
}

void	write_to_file(t_value *sh, int i)
{
	int fd;

	sh->file = sh->arg[i];
	fd = open(sh->file, O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (!fd)
		return;
	dup2(fd, 1);
	close(fd);
}

void	redi_to_file(t_value *sh, int i)
{
	int fd;

	sh->file = sh->arg[i];
	fd = open(sh->file, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (!fd)
		return;
	dup2(fd, 1);
	close(fd);
}

int	pars_command(t_value *sh)
{
	int i = 0;

	while (sh->arg[i]) {
		if (my_strcmp(sh->arg[i], ">") == 0) {
			redi_to_file(sh, i + 1);
			sh->arg[i] = NULL;
		}
		if (my_strcmp(sh->arg[i], ">>") == 0) {
			write_to_file(sh, i + 1);
			sh->arg[i] = NULL;
		}
		if (my_strcmp(sh->arg[i], "<") == 0) {
			if (che_ouv(sh, i + 1) == 0) return (0);
			sh->arg[i] = NULL;
		}
		if (my_strcmp(sh->arg[i], "<<") == 0)
			if (che_db_ouv(sh, i + 1) == 0) return (0);
		i += 1;
	}
	return (1);
}
