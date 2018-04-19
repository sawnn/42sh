/*
** EPITECH PROJECT, 2018
** call_ls
** File description:
** gaspacho andalou
*/

#include "my.h"

void	handle_errno(char **tab)
{
	if (errno == ENOEXEC) {
		write(2, tab[0], my_strlen(tab[0]));
		write(2, ": Exec format error.", 20);
		write(2, " Wrong Architecture.\n", 21);
		call_exit(1);
		exit(1);
	}
	if (errno == EACCES) {
		write(2, tab[0], my_strlen(tab[0]));
		write(2, ": Permission denied.\n", 21);
		exit(1);
	}
	else {
		write(1, tab[0], my_strlen(tab[0]));
		write(1, ": Command not found.\n", 21);
		call_exit(1);
		exit(1);
	}
}

int	len_tab(char **tab)
{
	int	i = -1;

	while (tab[++i]);
	return (i);
}

char	**add_color(char **tab)
{
	int	i = -1;
	char	**tab2 = NULL;

	if (my_strcmp(tab[0], "ls") != 0)
		return (tab);
	if ((tab2 = malloc(sizeof(char *) + len_tab(tab) +
				sizeof(char *))) == NULL)
		return (tab);
	while (tab[++i] != NULL)
		tab2[i] = my_strdup(tab[i]);
	tab2[0] = tab[0];
	tab2[i] = my_strdup("--color");
	tab2[i + 1] = NULL;
	free(tab);
	return (tab2);
}

void	command_not_found(char **tab, int i)
{
	if (i == 0 && execve(tab[0], tab, NULL) == -1) {
		handle_errno(tab);
		exit(1);
	}
	if (i == 1 && execve(tab[0], tab, NULL) == -1) {
		handle_errno(&tab[i + 1]);
		exit(1);
	}
}

int	call_command(t_shell *shell)
{
	pid_t	pid;
	int	z = 0;

	pid = fork();
	if (pid) {
		waitpid(pid, &z, 0);
		check_segfault(z);
	} else if (pid == 0) {
		if (shell->path) {
			shell->path = my_strcat(shell->path, "/");
			shell->path = my_strcat(shell->path, shell->tab[0]);
		}
		if (execve(shell->path, shell->tab, shell->env) == -1) {
			command_not_found(shell->tab, 0);
			exit(1);
		}
		handle_errno(shell->tab);
	}
	return (0);
}
