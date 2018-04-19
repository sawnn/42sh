/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/

#include "../include/my_printf.h"

void	flag_d(va_list ap, t_printf_u *test)
{
	int	nb = va_arg(ap, int);
	int	x = 1;

	if (nb == -2147483648) {
		my_putchar('-', test);
		my_putchar('2', test);
		nb = (nb + 2000000000);
		nb = nb * -1;
	}
	if (nb < 0) {
		my_putchar('-', test);
		nb = -1 * nb;
	}
	while ((nb / x) >= 10) {
		x = x * 10;
	}
	while (x != 0) {
		my_putchar((nb / x) % 10 + '0', test);
		x = x / 10;
	}
}
