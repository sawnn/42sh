/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** my_putstr
*/

#include "../include/my_printf.h"

void	flag_s(va_list ap, t_printf_u *test)
{
	int	i = 0;
	char	*str = va_arg(ap, char *);

	while (str[i] != '\0') {
		my_putchar(str[i], test);
		i = i + 1;
	}
}
