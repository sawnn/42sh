/*
** EPITECH PROJECT, 2017
** flag 3
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

void	flag_p(va_list ap, t_list *i)
{
	my_putstr("0x", i);
	my_putnbr_longbase(va_arg(ap, long), "0123456789abcdef", i);
}
