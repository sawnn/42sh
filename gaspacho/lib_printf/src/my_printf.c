/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** gaspacho andalou
*/

#include "../include/my.h"

void	print_flag(int j, va_list ap, t_list *i)
{
	void	(*fptr[13])(va_list, t_list*);

	fptr[0] = &flag_d;
	fptr[1] = &flag_d;
	fptr[2] = &flag_o;
	fptr[3] = &flag_u;
	fptr[4] = &flag_x;
	fptr[5] = &flag_big_x;
	fptr[6] = &flag_b;
	fptr[7] = &flag_c;
	fptr[8] = &flag_s;
	fptr[9] = &flag_big_s;
	fptr[10] = &flag_p;
	fptr[11] = &flag_modulo;
	fptr[12] = NULL;
	(*fptr[j])(ap, i);
}

void	display_char(char str, t_list *i)
{
	if (((str != '%') && (str >= 32 && str < 127)) || (str == '\n'))
		my_putchar(str, i);
}

void	printf_condition(int *j, char *str, va_list ap, t_list *i)
{
	if (str[*j + 1] && (check_flag_printf(str[*j + 1]) != 84)) {
		print_flag(check_flag_printf(str[*j + 1]), ap, i);
		(*j)++;
	}
	else if (check_flag_printf(str[*j]) == 84
			|| str[*j] == '%')
		my_putchar(str[*j], i);
}

int	my_printf(char *str, ...)
{
	va_list ap;
	int	j = -1;
	t_list	i;

	i.z = 0;
	va_start(ap, 0);
	while (str[++j] != '\0') {
		display_char(str[j], &i);
		if (str[j] == '%') {
			printf_condition(&j, str, ap, &i);
		}
	}
	va_end(ap);
	return (i.z);
}
