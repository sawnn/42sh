/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** string
*/

#include "my.h"

int	my_putstr(char const *str)
{
	int	a = -1;

	if (str == NULL)
		write(2, ": invalid string.", 17);
	else
		while (str[++a])
			my_putchar(str[a]);
	return (0);
}

int	flag_s(va_list ap)
{
	my_putstr(va_arg(ap, char*));
	return (0);
}
