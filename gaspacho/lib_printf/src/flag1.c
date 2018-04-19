/*
** EPITECH PROJECT, 2017
** flag
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

void	flag_d(va_list ap, t_list *i)
{
	my_put_nbr(va_arg(ap, int), i);
}

void	flag_u(va_list ap, t_list *i)
{
	my_put_unsigned_nbr(va_arg(ap, unsigned int), i);
}

void	flag_c(va_list ap, t_list *i)
{
	my_putchar(va_arg(ap, int), i);
}

void	flag_s(va_list ap, t_list *i)
{
	my_putstr(va_arg(ap, char *), i);
}

void	flag_modulo(va_list ap, t_list *i)
{
	my_putchar('%', i);
}
