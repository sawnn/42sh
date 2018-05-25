/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** binary
*/

#include "my.h"

int	my_put_bin(int nb)
{
	int	var = 1;

	if (nb < 0) {
		nb = nb * (-1);
		my_putchar('-');
	}
	while (nb / var >= 2)
		var = var * 2;
	while (var >= 1) {
		my_putchar((nb / var) + '0');
		nb = nb % var;
		var = (var / 2);
	}
	return (0);
}

int	flag_b(va_list ap)
{
	int nb = va_arg(ap, int);
	my_put_bin(nb);
	return (0);
}
