/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** hexa maj
*/

#include "my.h"

int	my_put_hexa2(int nb)
{
	int	n = 0;

	if (nb < 0) {
		nb = nb * (-1);
		my_putchar('-');
	}
	if (nb > 0) {
		my_put_hexa2(nb / 16);
		n = nb % 16;
		if (n + '0' > '9')
			n = n + 7;
		my_putchar(n + '0');
	}
	return (0);
}

int	flag_big_x(va_list ap)
{
	int nb = va_arg(ap, int);
	my_put_hexa2(nb);
	return (0);
}
