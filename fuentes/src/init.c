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

int	or_and(char	*str)
{
	int	a = -1;
	int	or = 0;
	int	and = 0;

	if (!str)
		return (0);
	while (str[++a]) {
		if (str[a+1] && str[a] == '|' && str[a + 1] == '|') {
			or += 2;
			continue;
		}
		if (str[a+1] && str[a] == '&' && str[a + 1] == '&') {
			and += 2;
			continue;
		}
	}
	if (or >= 2) return (1);
	if (and >= 2) return (2);
	return (0);
}

char	*brut_environement(use_value *use, char **env)
{
	char	*tmp;

	tmp = "/usr/local/bin:/usr/bin:/bin";
	return (tmp);
}

char	*is_inibhitor(char *epured)
{
	int	a = 0;
	char	*save = malloc(sizeof(char *) * my_strlen(epured) + 1);
	int	c = 0;

	while (epured[a]) {
		if (epured[a] == '\\') {
			if (epured[a+1] && epured[a+1] != '\0') {
				epured[a] =  '"';
				c += 1;
				a += 2;
				continue;
			} else {
				epured[a-1] && epured[a-1] != ' ' ?
					(epured[a] = ' ') : (epured[a] = '\0');
				write(1, "? ", 2);
				if ((save = get_next_line(0)) == NULL)
					return (epured);
				epured = (my_strcat(epured, save));
				a += 1;
				continue;
			}
		}
		if (epured[a] == ' ' && c != 0) {
			epured[a] = '"';
			c = 0;
		}
		a += 1;
	}
	if (epured[a] == '\0' && c == 1) {
		epured[a] = '"';
		epured[a+1] = '\0';
	}
	return (epured);
}

void	init_values(use_value *use, char **env)
{
	char	*epur_get; int	a = 0;

	use->points = -1;
	env[0] == NULL ? (use->epur = brut_environement(use, env)) :
		(use->epur = environement(env));
	use->envi = epur_path(use->epur);
	use->path = malloc(sizeof(char) * my_strlen(use->envi) + 1);
	if ((epur_get = get_next_line(0)) == NULL)
		exit(0);
	epur_get = is_inibhitor(epur_get);
	epur_get = epur_str(epur_get);
	use->epured = strdup(epur_get);
	a = or_and(epur_get);
	if (a != 0) {
		a == 1 ?
			(use->multi = word_tab_or(epur_get, '|'), use->o_a='|'):
			(use->multi = word_tab_or(epur_get, '&'), use->o_a='&');
	} else {
		use->points = multi_tab(epur_get);
		use->points == 0?(use->arg = my_str_to_word_tab(epur_get, ' ')):
		(use->multi = my_str_to_word_tab(epur_get, ';'));
	}
	use->path = my_str_to_word_tab(use->envi, ':');
	use->a = 0; use->b = 0; use->clms = 0; use->exit = 0;
}
