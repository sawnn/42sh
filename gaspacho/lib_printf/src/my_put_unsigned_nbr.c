/*
** EPITECH PROJECT, 2017
** unsigned putnbr
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

int	my_put_unsigned_nbr(unsigned int nb, t_list *i)
{
	int	x = 1;

	while ((nb / x) >= 10)
		x = x * 10;
	while (x != 0) {
		my_putchar(((nb/ x) % 10 + 48), i);
		x = x / 10;
	}
	return (0);
}
