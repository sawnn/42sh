/*
** EPITECH PROJECT, 2018
** where
** File description:
** gaspacho andalou
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	my_where(char *path, char *str)
{
	char	**tab = my_str_to_wordtab(path, ':');
	int	i = -1;
	char	*tmp = NULL;

	while (tab[++i] != NULL) {
		tmp = strcat(tab[i], "/");
		tmp = strcat(tmp, str);
		if (access(tmp, F_OK) == 0) {
			printf("%s\n", tmp);
			free(tmp);
			return (0);
		}
		free(tmp);
	}
	return (1);

}

int	main(int ac, char **av)
{
	int	i = 0;
	char *path = "/bin:/usr/bin:/usr/local/bin";
	while (av[++i] != NULL)
		my_where(path, av[i]);
	return (0);
}
