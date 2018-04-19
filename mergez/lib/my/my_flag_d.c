/*
** EPITECH PROJECT, 2017
** flag c
** File description:
** flag c
*/

#include <unistd.h>
#include "my.h"

void	cut(int *flag, int *nb, int *n)
{
	if (*flag == 1)
	{
		my_putchar('-');
		my_put_nbr(*nb / 10);
		*n = *nb % 10;
		my_putchar(8 + '0');
		*flag = 0;
	}
	else
	{
		my_put_nbr(*nb / 10);
		*n = *nb % 10;
		my_putchar(*n + '0');
	}
}

int	my_put_nbr(int nb)
{
	int n = 0;
	int flag = 0;

	if (nb < 0) {
		if (nb == -2147483648)
			nb = nb + 1;
		nb = nb * -1;
		if (nb == 2147483647)
			flag = 1;
	}
	if (nb < 10) {
		my_putchar(nb + '0');
	}
	else if (nb > 9)
		cut(&flag, &nb, &n);
}

int	my_flag_d(va_list ap)
{
	my_put_nbr(va_arg(ap, int));
	return (0);
}
