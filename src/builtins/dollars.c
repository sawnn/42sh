/*
** EPITECH PROJECT, 2018
** dollard
** File description:
** .c
*/

#include "../../include/my_sh.h"

char	*after_char(char *str, char c)
{
	int i = 0;

	while (str[i] != c)
		i += 1;
	return (&str[i + 1]);
}

int	count_bracket(char *str)
{
	int i = 0;
	int nb = 0;

	while (str[i]) {
		if (str[i] == '{' || str[i] == '}')
			nb += 1;
		i += 1;
	}
	return (nb);
}

char	*check(char *str, int *index)
{
	int i = 0;
	int j = 0;

	while (str[i]) {
		if (str[i] == '{')
			j = i + 1;
		if (str[i] == '}') {
			str[i] = '\0';
			*index = i;
			return (&str[j]);
		}
		i += 1;
	}
	return (str);
}

char	*dollars(char *str, t_set *list, node **head)
{
	t_set *tmp = list; node *env = (*head); int	index = 0;

	str = check(str, &index);
	while (tmp) {
		if (strcmp(tmp->op, str) == 0)
			return ((index == 0) ? (tmp->value)
				: (my_strcat(tmp->value, &str[index])));
		tmp = tmp->next;
	}
	while (env) {
		if (my_strncmp(env->str, str, my_strlen(str)) == 0) {
			return ((index == 0) ? (after_char(env->str, '='))
				: (my_strcat(after_char(env->str, '='),
					&str[index])));
		}
		env = env->next;
	}
	printf("%s: Undefined variable.\n", str);
	return (NULL);
}
