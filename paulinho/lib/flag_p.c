/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** pointer
*/

#include "my.h"

int	my_put_pointer(unsigned long nb)
{
	long	n = 0;

	if (nb > 0) {
		my_put_pointer(nb / 16);
		n = nb % 16;
		if (n + '0' > '9')
			n = n + 39;
		my_putchar(n + '0');
	}
	return (0);
}

int	my_putstr2(char const *c)
{
	int	a = -1;

	while (c[++a])
		my_putchar(c[a]);
	return (0);
}

int	flag_p(va_list ap)
{
	my_putstr2("0x");
	my_put_pointer(va_arg(ap, unsigned long));
	return (0);
}
