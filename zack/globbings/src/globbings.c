/*
** EPITECH PROJECT, 2018
** globbings
** File description:
** gaspacho andalou
*/

#include "my.h"

int	is_glob(char *str)
{
	int	i = -1;

	if (!str)
		return (84);
	while (str[++i] != 0)
		if (str[i] == '*' || str[i] == '?'
			|| str[i] == '[' || str[i] == ']')
			return (1);
	return (0);
}

int	get_offs(char **tab)
{
	int	i = -1;
	int	j = 0;

	while (tab[++i] != NULL)
		if (is_glob(tab[i]) == 0)
			j += 1;
	return (j);
}

void	exec_glob(char **tab, glob_t globbuf)
{
	int	j = -1;
	int	k = 0;
	while (tab[++j] != NULL) {
		if (is_glob(tab[j]) == 0) {
			globbuf.gl_pathv[k] = tab[j];
			k += 1;
		}
	}
	execvp(tab[0], &globbuf.gl_pathv[0]);
}

int	my_glob(char **tab)
{
	int	i = -1;
	glob_t	globbuf = {};

	globbuf.gl_offs = get_offs(tab);
	while (tab[++i] != NULL)
		if (is_glob(tab[i]) == 1)
			break;
	if (!tab[i])
		return (84);
	if (glob(tab[i], GLOB_DOOFFS, NULL, &globbuf) == GLOB_NOMATCH)
		printf("%s: No match\n", tab[0]);
	while (tab[++i] != NULL) {
		if (is_glob(tab[i]) == 1 &&
			glob(tab[i], GLOB_DOOFFS |
				GLOB_APPEND, NULL, &globbuf) == GLOB_NOMATCH) {
			printf("%s: No match\n", tab[0]);
		}
	}
	exec_glob(tab, globbuf);
	return (0);
}

int	main(int ac, char **av)
{
	char	**tab = NULL;

	av[1] ? tab = my_str_to_wordtab(av[1], ' ') : exit(84);
	if (tab)
		if (my_glob(tab) == 84)
			return (84);
	return (0);
}
