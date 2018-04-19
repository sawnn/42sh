/*
** EPITECH PROJECT, 2017
** flag_X.c
** File description:
** flag_X.c
*/

#include "../include/my_printf.h"

void	flag_x_big(va_list ap, t_printf_u *test)
{
	unsigned int	nb = va_arg(ap, unsigned int);
	char		*base = "0123456789ABCDEF";

	my_put_nbr_base(nb, base, test);
}
