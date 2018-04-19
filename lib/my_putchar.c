/*
** EPITECH PROJECT, 2017
** my_putchar.c
** File description:
** my_putchar.c
*/

#include "../include/my_printf.h"

void	my_putchar(char c, t_printf_u *test)
{
	test->u = test->u + 1;
	write(1, &c, 1);
}

void	my_put_char(char c)
{
	write(1, &c, 1);
}
