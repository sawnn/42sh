/*
** EPITECH PROJECT, 2017
** flag c
** File description:
** flag c
*/

#include <unistd.h>
#include "my.h"

int	my_flag_c(va_list ap)
{
	my_putchar(va_arg(ap, int));
	return (0);
}
