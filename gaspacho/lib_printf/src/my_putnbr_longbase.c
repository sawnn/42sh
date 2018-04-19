/*
** EPITECH PROJECT, 2017
** putnbrlongbase
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

int	my_putnbr_longbase(unsigned long nb, char *base, t_list *i)
{
	long	x = 1;
	long	charac = 0;
	unsigned long	len = my_strlen(base);

	while ((nb / x) >= len)
		x *= len;
	while (x > 0) {
		charac = (nb / x) % len;
		my_putchar(base[charac], i);
		x /= len;
	}
	return (0);
}
