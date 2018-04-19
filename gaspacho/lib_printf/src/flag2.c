/*
** EPITECH PROJECT, 2017
** flag2
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

void	flag_o(va_list ap, t_list *i)
{
	my_putnbr_base(va_arg(ap, unsigned int), "01234567", i);
}

void	flag_x(va_list ap, t_list *i)
{
	my_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", i);
}

void	flag_big_x(va_list ap, t_list *i)
{
	my_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", i);
}

void	flag_b(va_list ap, t_list *i)
{
	my_putnbr_bin(va_arg(ap, unsigned int), i);
}
