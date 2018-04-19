/*
** EPITECH PROJECT, 2017
** flag S
** File description:
** flag S
*/

#include <unistd.h>
#include "my.h"

int	my_put_nbrocta(unsigned int nb)
{
	int n = 0;

	if (nb > 0) {
		my_put_nbrocta(nb / 8);
		n = nb % 8;
		my_putchar(n + '0');
	}
}

int	my_putstr2(const char *str)
{
	int i = 0;

	if (str == NULL)
		my_putstr2("(null)");
	else
		while (str[i]) {
			if (str[i] < 32 || str[i] >= 127) {
				my_putchar('\\');
				if (str[i] < 8) {
					my_putchar('0');
					my_putchar('0');
				}
				else if (str[i] >= 8)
					my_putchar('0');
				my_put_nbrocta(str[i]);
			}
			else
				my_putchar(str[i]);
			i = i + 1;
		}
}

int	my_flag_ss(va_list ap)
{
	my_putstr2(va_arg(ap, char*));
	return (0);
}
