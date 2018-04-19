/*
** EPITECH PROJECT, 2017
** my_put_nbr_base.c
** File description:
** my_put_nbr_base.c
*/

#include "../include/my_printf.h"

int	my_put_nbr_base(unsigned int nb, char *base, t_printf_u *test)
{
	int	div = 1;
	int	res;
	int	length = my_strlen(base);

	while ((nb / div) >= length)
		div = div * length;
	while (div > 0) {
		res = (nb / div) % length;
		my_putchar(base[res], test);
		div = div / length;
	}
}
