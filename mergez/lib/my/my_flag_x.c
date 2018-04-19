/*
** EPITECH PROJECT, 2017
** flag x
** File description:
** flag x
*/

#include <unistd.h>
#include "my.h"

int	my_put_nbrhexa(unsigned int nb)
{
	int n = 0;

	if (nb > 0) {
		my_put_nbrhexa(nb / 16);
		n = nb % 16;
		if (n + '0' > 57)
			n = n + 39;
		my_putchar(n + '0');
	}
}

int	my_flag_x(va_list ap)
{
	my_put_nbrhexa(va_arg(ap,unsigned int));
	return (0);
}
