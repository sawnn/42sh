/*
** EPITECH PROJECT, 2017
** flag u
** File description:
** flag u
*/

#include <unistd.h>
#include "my.h"

int	my_put_nbr1(unsigned int nb)
{
	int n = 0;

	if (nb < 10) {
		my_putchar(nb + '0');
	}
	else if (nb > 9) {
		my_put_nbr1(nb / 10);
		n = nb % 10;
		my_putchar(n + '0');
	}
}

int	my_flag_u(va_list ap)
{
	my_put_nbr1(va_arg(ap,unsigned int));
	return (0);
}
