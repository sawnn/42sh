/*
** EPITECH PROJECT, 2017
** flag_b.c
** File description:
** flag_b.c
*/

#include "../include/my_printf.h"

void	flag_b(va_list ap, t_printf_u *test)
{
	unsigned int	nb = va_arg(ap, unsigned int);
	char		*base = "01";

	my_put_nbr_base(nb, base, test);
}
