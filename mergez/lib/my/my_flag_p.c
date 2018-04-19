/*
** EPITECH PROJECT, 2017
** flag p
** File description:
** flag p
*/

#include <unistd.h>
#include "my.h"

int	my_put_nbradress(unsigned long nb)
{
	long n = 0;

	if (nb > 0) {
		my_put_nbradress(nb / 16);
		n = nb % 16;
		if (n + '0' > 57)
			n = n + 39;
		my_putchar(n + '0');
	}
}

int	my_flag_p(va_list ap)
{
	my_putchar('0');
	my_putchar('x');
	my_put_nbradress(va_arg(ap, unsigned long));
	return (0);
}
