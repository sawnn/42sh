/*
** EPITECH PROJECT, 2017
** flag_p.c
** File description:
** flag_p.c
*/

#include "../include/my_printf.h"

void	flag_p(va_list ap, t_printf_u *test)
{
	unsigned long	nb = va_arg(ap, unsigned long);

	my_putchar('0', test);
	my_putchar('x', test);
	my_put_nbr_base_p(nb, "0123456789abcdef", test);
}
