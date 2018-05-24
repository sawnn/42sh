/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../../include/my_sh.h"

int	is_alph(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	sym(char c, char sym)
{
	if ((c < 'a' || c > 'z') || c == sym)
		return (1);
	return (0);
}
