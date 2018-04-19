/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** gaspacho andalou
*/

#include <unistd.h>
#include "../include/my.h"

int	limit(int nb, t_list *i)
{
	if (nb <= -2147483648) {
		my_putchar('-', i);
		my_putchar(50, i);
		return (147483648);
	}
	return (nb);
}

int	my_put_nbr(int nb, t_list *i)
{
	int	x = 1;

	nb = limit(nb, i);
	if (nb < 0) {
		nb = nb * (-1);
		my_putchar('-', i);
	}
	while ((nb / x) >= 10) {
		x = x * 10;
	}
	while (x != 0) {
		my_putchar(((nb / x) % 10 + '0'), i);
		x = x / 10;
	}
	return (0);
}
