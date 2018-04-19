/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** unsigned int
*/

#include "my.h"

int	my_put_unsigned(unsigned int nb)
{
	int	var = 1;

	while (nb / var >= 10)
		var = var * 10;
	while (var >= 1) {
		my_putchar((nb / var) + '0');
		nb = nb % var;
		var = (var / 10);
	}
	return (0);
}

int	flag_u(va_list ap)
{
	int nb = va_arg(ap, unsigned int);
	my_put_unsigned(nb);
	return (0);
}
