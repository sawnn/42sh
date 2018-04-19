/*
** EPITECH PROJECT, 2017
** printfh
** File description:
** gaspacho andalou
*/

#ifndef PRINTF_H
#define PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct s_list {
	int z;
}t_list;

char	*my_strcpy(char *dest, char const *src);
void	my_putchar(char c, t_list *i);
void	my_putchar_error(char c, t_list *i);
int	my_printf(char *str, ...);
int	my_putstr(char *str, t_list *i);
int	my_putstr_error(char *str, t_list *i);
int	my_strlen(char *str);
int     my_put_unsigned_nbr(unsigned int nb, t_list *i);
int	my_put_nbr(int nb, t_list *i);
int	my_putnbr_base(unsigned int nb, char *base, t_list *i);
int	my_putnbr_longbase(unsigned long nb, char *base, t_list *i);
int	my_putnbr_bin(unsigned int nb, t_list *i);
int	check_flag_printf(char flag);
int	handle_charac(char *str, char c, int j, va_list ap, t_list *i);
int	handle(int j, char *str, va_list ap, t_list *i);
void	printf_condition(int *j, char *str, va_list ap, t_list *i);
void	print_and_space(char str, char c, t_list *i, va_list ap);
void	add_prefix(char str, t_list *i);
void	display_char(char str, t_list *i);
void	print_flag(int j, va_list ap, t_list *i);
void	flag_d(va_list ap, t_list *i);
void	flag_i(va_list ap, t_list *i);
void	flag_u(va_list ap, t_list *i);
void	flag_s(va_list ap, t_list *i);
void	flag_big_s(va_list ap, t_list *i);
void	flag_c(va_list ap, t_list *i);
void	flag_x(va_list ap, t_list *i);
void	flag_big_x(va_list ap, t_list *i);
void	flag_o(va_list ap, t_list *i);
void	flag_b(va_list ap, t_list *i);
void	flag_modulo(va_list ap, t_list *i);
void	flag_p(va_list ap, t_list *i);
void	display_below(char str, t_list *i);
int	precision(char *str, int j, t_list *i, va_list ap);
int	my_getnbr(char *str, t_list *i);

#endif /*PRINTF_H*/
