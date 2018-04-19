/*
** EPITECH PROJECT, 2017
** minishell 1
** File description:
** sample
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/gnl.h"
#include "my.h"

int	main(void)
{
	char	*s;
	int	end;

	end = 0;
	while (!end)
	{
		s = get_next_line(0);
		if (s > 0)
			my_printf("Next line : %s\n", s);
		else
			end = !end;
	}
	return (0);
}
