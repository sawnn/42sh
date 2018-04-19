/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int	my_str_isalpha(char const *str);
char	*my_strdup(char *str);
int	my_strncmp(char const *s1, char const *s2, int n);
char	**my_str_to_wordtab(char *str, char);
char	*my_strcat(char *dest, char const *src);
int	my_strlen(char const *str);
int	my_putstr(char const *str);
int	my_printf(const char *str, ...);
int	my_flag_s(va_list ap);
int	my_flag_c(va_list ap);
int	my_flag_d(va_list ap);
int	my_flag_modulo(va_list ap);
int	my_flag_u(va_list ap);
int	my_flag_b(va_list ap);
int	my_flag_x(va_list ap);
int	my_flag_xx(va_list ap);
int	my_flag_o(va_list ap);
int	my_flag_p(va_list ap);
int	my_flag_ss(va_list ap);
int	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char const *str);
int	my_getnbr(char const *str);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char const *src);
char	*get_next_line(int fd);

#endif /*MY_H_*/
