/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** my_putstr
*/

#include "my.h"

int	my_putstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == '+' || str[i] == '-' ||
			str[i] == '%' || str[i] == '*' || str[i] == '/') {
			my_putchar(str[i]);
			my_putchar(' ');
			i = i + 1;
		}
		else {
			my_put_nbr(str[i]);
			my_putchar(' ');
			i = i + 1;
		}
	}
	return (0);
}
