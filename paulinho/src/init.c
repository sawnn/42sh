/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** Initialization
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

int	multi_tab(char	*str)
{
	int	a = -1;
	int	points = 0;

	if (!str)
		return (0);
	while (str[++a])
		if (str[a] == ';')
			points += 1;
	return (points);
}

char	*brut_environement(use_value *use, char **env)
{
	char	*tmp;

	tmp = "/usr/local/bin:/usr/bin:/bin";
	return (tmp);
}

void	init_values(use_value *use, char **env)
{
	char	*epur_get;

	use->points = -1;
	env[0] == NULL ? (use->epur = brut_environement(use, env)) :
		(use->epur = environement(env));
	use->envi = epur_path(use->epur);
	use->path = malloc(sizeof(char) * my_strlen(use->envi) + 1);
	epur_get = epur_str(get_next_line(0));
	use->points = multi_tab(epur_get);
	use->points == 0 ? (use->arg = my_str_to_word_tab(epur_get, ' ')) :
		(use->multi = my_str_to_word_tab(epur_get, ';'));
	use->path = my_str_to_word_tab(use->envi, ':');
	use->a = 0;
	use->b = 0;
	use->clms = 0;
	use->exit = 0;
}
