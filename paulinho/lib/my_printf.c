/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** main
*/

#include "my.h"

int	flags_detect(char c)
{
	int	b = 0;
	char	flag[12] = "c%siduboxXpS";

	while (b < 12) {
		if (c == flag[b])
			return (b);
		b += 1;
	}
	return (99);
}

int	tabl(int a, va_list ap)
{
	int	(*stab[12])(va_list);

	stab[0] = &flag_c;
	stab[1] = &flag_modulo;
	stab[2] = &flag_s;
	stab[3] = &flag_i;
	stab[4] = &flag_d;
	stab[5] = &flag_u;
	stab[6] = &flag_b;
	stab[7] = &flag_o;
	stab[8] = &flag_x;
	stab[9] = &flag_big_x;
	stab[10]= &flag_p;
	stab[11]= &flag_big_s;
	stab[a](ap);
	return (0);
}

int	*my_printf(char const *str, ...)
{
	int	a = -1;
	int	space = 1;
	va_list	ap;

	va_start(ap, str);
	while (str[++a]) {
		while (str[a] == '%' && flags_detect(str[a + space]) == 99)
			space = space + 1;
		if (str[a] == '%' && flags_detect(str[a + space]) != 99) {
			tabl(flags_detect(str[a + space]),(ap));
			a = a + space;
		}
		else
			write(1, &str[a], 1);
	}
	va_end(ap);
	return (0);
}
