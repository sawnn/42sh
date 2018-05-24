/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../../include/my_sh.h"

int	clear_string(char **str)
{
	char *new = my_epure_str(*str);

	if (new == NULL)
		return (-1);
	*str = new;
	return (0);
}

int	parsor_checker(int i, char **str)
{
	int	(*fptr[4])(char **);

	fptr[0] = clear_string;
	fptr[1] = clear_semicolon;
	//fptr[2] = clear_ampersand;
	fptr[3] = NULL;
	return ((*fptr[i])(str));
}

int	launch_checker_parsor(t_mini *mini, char *str)
{
	int	i = 0;

	while (i != 2) {
		if (parsor_checker(i, &str) == -1) {
			printf("Error heicha my friend\n");
			mini->global = 1;
			return (-1);
		}
		i += 1;
	}
	mini->buf = str;
	return (0);
}
