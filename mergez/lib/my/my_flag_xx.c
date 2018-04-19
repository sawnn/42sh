/*
** EPITECH PROJECT, 2017
** flag
** File description:
** flag
*/

#include <unistd.h>
#include "my.h"

int	my_put_nbrhex(unsigned int nb)
{
	int n = 0;

	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
	}
	if (nb > 0) {
		my_put_nbrhex(nb / 16);
		n = nb % 16;
		if (n + '0' > 57)
			n = n + 7;
		my_putchar(n + '0');
	}
}

int	my_flag_xx(va_list ap)
{
	my_put_nbrhex(va_arg(ap,unsigned int));
	return (0);
}
