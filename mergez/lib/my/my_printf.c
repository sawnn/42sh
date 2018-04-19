/*
** EPITECH PROJECT, 2017
** printf
** File description:
** printf
*/

#include "my.h"
#include <unistd.h>
#include <stdarg.h>

int	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_tab(va_list ap, int i)
{
	int (*ftab[12])(va_list);
	ftab[0] = &my_flag_s;
	ftab[1] = &my_flag_c;
	ftab[2] = &my_flag_d;
	ftab[3] = &my_flag_d;
	ftab[4] = &my_flag_modulo;
	ftab[5] = &my_flag_u;
	ftab[6] = &my_flag_b;
	ftab[7] = &my_flag_x;
	ftab[8] = &my_flag_xx;
	ftab[9] = &my_flag_o;
	ftab[10] = &my_flag_p;
	ftab[11] = &my_flag_ss;
	(ftab[i])(ap);
}

int	check_flags(char c)
{
	int a = 0;
	char flag[12] = "scdi%ubxXopS";

	while (a < 12) {
		if (c == flag[a])
			return (a);
		a = a + 1;
	}
	return (-1);
}

int	my_printf(const char *str, ...)
{
	int i = 0;
	int space = 1;
	va_list ap;

	va_start(ap, str);
	while (str[i]) {
		while (str[i] == '%' && check_flags(str[i + space]) == -1)
			space = space + 1;
		if (str[i] == '%' && check_flags(str[i + space]) != -1) {
			my_tab(ap, check_flags(str[i + space]));
			i = i + space;
		}
		else
			my_putchar(str[i]);
		i = i + 1;
	}
	va_end(ap);
	return (0);
}
