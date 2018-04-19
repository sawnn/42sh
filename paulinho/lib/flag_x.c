/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** hexa min
*/

#include "my.h"

int	my_put_hexa(int nb)
{
	int	n = 0;

	if (nb < 0) {
		nb = nb * (-1);
		my_putchar('-');
	}
	if (nb > 0) {
		my_put_hexa(nb / 16);
		n = nb % 16;
		if (n + '0' > '9')
			n = n + 39;
		my_putchar(n + '0');
	}
	return (0);
}

int	flag_x(va_list ap)
{
	int nb = va_arg(ap, int);
	my_put_hexa(nb);
	return (0);
}
