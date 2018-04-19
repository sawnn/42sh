/*
** EPITECH PROJECT, 2017
** flag_u.c
** File description:
** flag_u.c
*/

#include "../include/my_printf.h"

void	flag_u(va_list ap, t_printf_u *test)
{
	unsigned int	nb = va_arg(ap, int);
	int		x = 1;

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
