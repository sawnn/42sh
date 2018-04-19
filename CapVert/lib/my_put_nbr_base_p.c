/*
** EPITECH PROJECT, 2017
** my_put_nbr_base_p.c
** File description:
** my_put_nbr_base_p.c
*/

#include "../include/my_printf.h"

int	my_put_nbr_base_p(unsigned long nb, char *base, t_printf_u *test)
{
	long	div = 1;
	long	res;
	long	length = my_strlen(base);

	while ((nb / div) >= length)
		div = div * length;
	while (div > 0) {
		res = (nb / div) % length;
		my_putchar(base[res], test);
		div = div / length;
	}
}
