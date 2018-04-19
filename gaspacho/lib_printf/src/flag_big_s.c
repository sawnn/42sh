/*
** EPITECH PROJECT, 2017
** flag_S
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

void	display_below(char str, t_list *i)
{
	if (str < 8) {
		my_putchar('\\', i);
		my_putstr("00", i);
		my_putchar(my_putnbr_base(str, "01234567", i), i);
	}
	else if (str > 7 && str < 32) {
		my_putchar('\\', i);
		my_putchar('0', i);
		my_putchar(my_putnbr_base(str, "01234567", i), i);
	}
	else
		display_char(str, i);
}

void	flag_big_s(va_list ap, t_list *i)
{
	int	j = -1;
	char	*str = va_arg(ap, char *);

	if (str == NULL) {
		my_putstr_error("Invalid\n", i);
		return;
	}
	while (str[++j] != '\0') {
		if (str[j] < 32) {
			display_below(str[j], i);
		}
		else if (str[j] >= 127) {
			my_putchar('\\', i);
			my_putchar(my_putnbr_base(str[j], "01234567", i), i);
		}
		else
			display_char(str[j], i);
	}
}
