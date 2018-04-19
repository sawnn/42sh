/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** my_printf.c
*/

#include "../include/my_printf.h"

int	remove_space(char *str, int j)
{
	while (str[++j] == ' ');
	if (str[j] == '\0')
		return (0);
	return (j);

}

int	check_flag(char c)
{
	int	i = 0;
	char	flag[12] = "sdcbxXopuSi%";

	while (i < 12) {
		if (c == flag[i])
			return (i);
		i = i + 1;
	}
	return (84);
}

void	*my_fptr(int i, va_list ap, t_printf_u *test)
{
	void	(*fptr[21])(va_list, t_printf_u*);
	fptr[0] = &flag_s;
	fptr[1] = &flag_d;
	fptr[2] = &flag_c;
	fptr[3] = &flag_b;
	fptr[4] = &flag_x;
	fptr[5] = &flag_x_big;
	fptr[6] = &flag_o;
	fptr[7] = &flag_p;
	fptr[8] = &flag_u;
	fptr[9] = &flag_s_big;
	fptr[10] = &flag_i;
	fptr[11] = &flag_mod;
	(*fptr[i])(ap, test);
}

void	display(char *str, t_printf_u *test, int i)
{
	if (str[i] != '%') {
		my_putchar(str[i], test);
		i++;
	}
}

int	my_printf(char *str, ...)
{
	int		i = -1;
	int		j = 0;
	va_list		ap;
	t_printf_u	test;

	test.u = 0;
	va_start(ap, str);
	while (str[++i] != '\0') {
		display(str, &test, i);
		if (str[i] == '%') {
			j = remove_space(str, i);
			if (check_flag(str[j]) != 84) {
				my_fptr(check_flag(str[j]), ap, &test);
				init_int(&i, &j);
			} else
				my_putchar('%', &test);
		}
	}
	va_end(ap);
	return (test.u);
}
