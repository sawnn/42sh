/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** int
*/

#include "my.h"

int	my_put_nbr2(int nb)
{
	int	var = 1;

	if (nb < 0) {
		nb = nb * (-1);
		my_putchar('-');
	}
	while (nb / var >= 10)
		var = var * 10;
	while (var >= 1) {
		my_putchar((nb / var) + '0');
		nb = nb % var;
		var = (var / 10);
	}
	return (0);
}

int	flag_d(va_list ap)
{
	int nb = va_arg(ap, int);
	my_put_nbr2(nb);
	return (0);
}
