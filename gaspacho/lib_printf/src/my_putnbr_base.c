/*
** EPITECH PROJECT, 2017
** putnbrbase
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

int	my_putnbr_base(unsigned int nb, char *base, t_list *i)
{
	int	x = 1;
	int	charac = 0;
	unsigned	len = my_strlen(base);

	while ((nb /x) >= len)
		x *= len;
	while (x > 0) {
		charac = (nb / x) % len;
		my_putchar(base[charac], i);
		x = x / len;
	}
	return (0);
}
