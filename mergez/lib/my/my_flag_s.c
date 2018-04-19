/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** my_putstr
*/

#include "my.h"

int	my_putstr(const char *str)
{
	int i = 0;

	if (str == NULL)
		my_putstr("(null)");
	else
		while (str[i]) {
			my_putchar(str[i]);
			i = i + 1;
		}
}

int	my_flag_s(va_list ap)
{
	my_putstr(va_arg(ap, char*));
	return (0);
}
