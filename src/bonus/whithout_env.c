/*
** EPITECH PROJECT, 2018
** whithout env
** File description:
** get a simple env
*/

#include "../../include/my_sh.h"

void	get_simple_env(node **head)
{
	char	hostname[1024];
	char	user[1024];

	gethostname(hostname, 1024);
	getlogin_r(user, 1024);
	*head = add_link(*head, my_strcat("USER=", user));
	*head = add_link(*head, my_strcat("HOST=", hostname));
}
