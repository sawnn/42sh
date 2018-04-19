/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** character non-printable
*/

#include "my.h"

int	my_put_oct2(int nb)
{
	int	var = 1;

	while (nb / var >= 8)
		var = var * 8;
	while (var >= 1) {
		my_putchar((nb / var) + '0');
		nb = nb % var;
		var = (var / 8);
	}
	return (0);
}

int	my_putstr3(char const *str)
{
	int	a = -1;

	if (str == NULL)
		write(2, ": invalid string.", 17);
	else
		while (str[++a]){
			if (str[a] < 32 || str[a] >= 127) {
				my_putchar('\\');
				if (str[a] < 8) {
					my_putchar('0');
					my_putchar('0');
				}
			my_put_oct2(str[a]);
			}
			else
				my_putchar(str[a]);
		}
	return (0);
}

int	flag_big_s(va_list ap)
{
	my_putstr3(va_arg(ap, char*));
	return (0);
}
