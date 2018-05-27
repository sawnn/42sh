/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../../include/my_sh.h"

char	*clear_string(char *str)
{
	char *new = my_epure_str(str);

	if (new == NULL)
		return (NULL);
	str = strdup(new);
	return (str);
}

char	*parsor_checker(int i, char *str)
{
	char *	(*fptr[4])(char *);

	fptr[0] = clear_string;
	fptr[1] = check_parentheses;
	fptr[2] = NULL;
	return ((*fptr[i])(str));
}

char	*launch_checker_parsor(t_mini *mini, char *str)
{
	int	i = 0;

	while (i != 2) {
		if (parsor_checker(i, str) == NULL) {
			mini->global = 1;
			return (NULL);
		}
		i += 1;
	}
	return (str);
}
