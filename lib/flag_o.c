/*
** EPITECH PROJECT, 2017
** flag_o.c
** File description:
** flag_o.c
*/

#include "../include/my_printf.h"

void	flag_o(va_list ap, t_printf_u *test)
{
	unsigned int	nb = va_arg(ap, unsigned int);
	char		*base = "01234567";

	my_put_nbr_base(nb, base, test);
}
