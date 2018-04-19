/*
** EPITECH PROJECT, 2017
** puterro
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

void	my_putchar_error(char c, t_list *i)
{
	i->z = i->z + 1;
	write(2, &c, 1);
}
