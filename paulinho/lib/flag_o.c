/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** octal
*/

#include "my.h"

int	my_put_oct(unsigned int nb)
{
	int	var = 1;

	while (nb / var >= 8)
		var = var * 8;
	while (var >= 1) {
		my_putchar((nb / var) + '0');
		nb = nb % var;
		var = (var / 8);
	}
	return (0);
}

int	flag_o(va_list ap)
{
	int nb = va_arg(ap, int);
	my_put_oct(nb);
	return (0);
}
