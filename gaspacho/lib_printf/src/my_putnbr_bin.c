/*
** EPITECH PROJECT, 2017
** putnbrbin
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

int	my_putnbr_bin(unsigned int nb, t_list *i)
{
	int	x = 1;

	while ((nb / x) >= 2)
		x = x * 2;
	while (x > 0) {
		my_putchar(((nb / x) % 2 + 48), i);
		x = x / 2;
	}
	return (0);
}
