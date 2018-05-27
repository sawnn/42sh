/*
** EPITECH PROJECT, 2018
** func if
** File description:
** function for if
*/

#include "../../include/my_sh.h"

int	equal_if(char **tab)
{
	if (strcmp(tab[0], tab[2]) == 0)
		return (1);
	return (0);
}

int	diff_if(char **tab)
{
	if (strcmp(tab[0], tab[2]) != 0)
		return (1);
	return (0);
}

int	infer_if(char **tab)
{
	if (is_num_for_if(tab[0]) != 1 || is_num_for_if(tab[2]) != 1)
		return (-1);
	if (atoi(tab[0]) < atoi(tab[2]))
		return (1);
	return (0);
}

int	infer_equal_if(char **tab)
{
	if (is_num_for_if(tab[0]) != 1 || is_num_for_if(tab[2]) != 1) {
		return (-1);
	}
	if (atoi(tab[0]) <= atoi(tab[2]))
		return (1);
	return (0);
}

int	superior_if(char **tab)
{
	if (is_num_for_if(tab[0]) != 1 || is_num_for_if(tab[2]) != 1)
		return (-1);
	if (atoi(tab[0]) > atoi(tab[2]))
		return (1);
	return (0);
}
