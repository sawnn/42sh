/*
** EPITECH PROJECT, 2017
** flag o
** File description:
** flag o
*/

#include <unistd.h>
#include "my.h"

int	my_put_nbroct(unsigned int nb)
{
	int n = 0;

	if (nb > 0) {
		my_put_nbroct(nb / 8);
		n = nb % 8;
		my_putchar(n + '0');
	}
}

int	my_flag_o(va_list ap)
{
	my_put_nbroct(va_arg(ap,unsigned int));
	return (0);
}
