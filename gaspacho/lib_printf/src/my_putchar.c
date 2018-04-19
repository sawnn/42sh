/*
** EPITECH PROJECT, 2017
** my_putchar
** File description:
** putchar
*/

#include "../include/my.h"

void	my_putchar(char c, t_list *i)
{
	i->z= i->z + 1;
	write(1, &c, 1);
}
