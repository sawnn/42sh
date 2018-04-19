/*
** EPITECH PROJECT, 2017
** flag_x.c
** File description:
** flag_x.c
*/

#include "../include/my_printf.h"

void	flag_x(va_list ap, t_printf_u *test)
{
	unsigned int	nb = va_arg(ap, unsigned int);
	char		*base = "0123456789abcdef";

	my_put_nbr_base(nb, base, test);
}
