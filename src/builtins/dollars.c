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

char	*dollars(char *str, t_set *list, node **head)
{
	t_set *tmp = list;
	node *env = (*head);

	while (tmp) {
		if (strcmp(tmp->op, str) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	while (env) {
		if (my_strncmp(env->str, str, my_strlen(str)) == 0)
			return (after_char(env->str, '='));
		env = env->next;
	}
	printf("%s: Undefined variable.\n", str);
	return (NULL);
}
