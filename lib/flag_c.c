/*
** EPITECH PROJECT, 2017
** my_putchar.c
** File description:
** my_putchar.c
*/

#include "../include/my_printf.h"
#include "stdarg.h"

void	flag_c(va_list ap, t_printf_u *test)
{
	char	c = va_arg(ap, int);

	my_putchar(c, test);
}
