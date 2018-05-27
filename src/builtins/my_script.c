/*
** EPITECH PROJECT, 2018
** scripting
** File description:
** gaspacho andalou
*/

#include "../../include/my_sh.h"

int	my_script(t_mini *mini)
{
	if (strcmp(mini->buf, "./mysc") == 0) {
		printf("42sh\nmysc\nrsc\n-e plop\n");
		return (0);
	}
	return (1);
}
