/*
** EPITECH PROJECT, 2017
** my_printf.h
** File description:
** my_printf.h
*/

#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
typedef struct s_printf_u {
	int	u;
} t_printf_u;

int	check_flag(char c);
int     my_printf(char *str, ...);
void	init_int(int *, int *);
void	*my_fptr(int i, va_list ap, t_printf_u *test);
void	my_putchar(char c, t_printf_u *test);
void	my_put_char(char c);
int	my_strlen(char *str);
int	my_put_nbr_base(unsigned int nb, char *base, t_printf_u *test);
int	my_put_nbr_base_p(unsigned long nb, char *base,  t_printf_u *test);
void	display(char *str, t_printf_u *test, int i);
void	flag_s(va_list ap, t_printf_u *test);
void	flag_d(va_list ap, t_printf_u *test);
void	flag_c(va_list ap, t_printf_u *test);
void	flag_b(va_list ap, t_printf_u *test);
void	flag_x(va_list ap, t_printf_u *test);
void	flag_x_big(va_list ap, t_printf_u *test);
void	flag_o(va_list ap, t_printf_u *test);
void	flag_p(va_list ap, t_printf_u *test);
void	flag_u(va_list ap, t_printf_u *test);
void	flag_s_big(va_list ap, t_printf_u *test);
void	flag_i(va_list ap, t_printf_u *test);
void	flag_p(va_list ap, t_printf_u *test);
void	flag_mod(va_list ap, t_printf_u *test);
void	black(va_list ap, t_printf_u *test);
void	red(va_list ap, t_printf_u *test);
void	green(va_list ap, t_printf_u *test);
void	yellow(va_list ap, t_printf_u *test);
void	blue(va_list ap, t_printf_u *test);
void	purple(va_list ap, t_printf_u *test);
void	cyan(va_list ap, t_printf_u *test);
void	grey(va_list ap, t_printf_u *test);
char	*my_strcat(char *dest, char *src);
char	*get_next_line(int);

#endif /*MY_PRINTF_H_*/
