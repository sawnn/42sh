/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** Unalias
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

char	**strdup_tab(char **tab)
{
	int	a = -1;
	char	**save = malloc(sizeof(char *) * size_tab(tab));

	while (tab[++a])
		save[a] = strdup(tab[a]);
	return (save);
}

void	unalias_func(char **tab, use_value *use)
{
	int	a = -1;
	int	b = 0;
	int	c = 0;
	char	***save = malloc(sizeof(char **) * 40);

	if (use->alias == NULL)
		return;
	while (use->alias[b] && use->alias[b][0]) {
		save[c] = malloc(sizeof(char*) * 3);
		while (use->arg[++a]) {
			if (strcmp(use->alias[b][0], use->b_arg[a]) == 0) {
				b += 1;
				continue;
			}
		}
		use->alias[b] != NULL ? save[c] = strdup_tab(use->alias[b]): (save[c] = NULL);
		a = -1;
		c += 1;
		b += 1;
	}
	use->alias = save;
	print_alias(save);
}
