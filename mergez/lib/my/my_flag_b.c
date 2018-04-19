/*
** EPITECH PROJECT, 2017
** flag b
** File description:
** flag b
*/

#include <unistd.h>
#include "my.h"

int	my_put_nbrbinary(int nb)
{
	int n = 0;

	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
	}
	if (nb > 0) {
		my_put_nbrbinary(nb / 2);
		n = nb % 2;
		my_putchar(n + '0');
	}
}

int	my_flag_b(va_list ap)
{
	my_put_nbrbinary(va_arg(ap, int));
	return (0);
}
