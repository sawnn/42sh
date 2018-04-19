/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** character
*/

#include "my.h"

int	flag_c(va_list ap)
{
	char c = (va_arg(ap, int));
	my_putchar(c);
	return (0);
}
