/*
** EPITECH PROJECT, 2018
** inibhitor
** File description:
** a
*/

#include "../../include/my_sh.h"

char	*is_inibhitor(char *epured)
{
	int	a = 0;
	char	*save = malloc(sizeof(char *) * my_strlen(epured) + 1);
	int	c = 0;

	while (epured[a]) {
		if (epured[a] == '\\') {
			if (epured[a+1] && epured[a+1] != '\0') {
				epured[a] =  '"';
				c += 1;
				a += 2;
				continue;
			} else {
				epured[a-1] && epured[a-1] != ' ' ?
					(epured[a] = ' ') : (epured[a] = '\0');
				write(1, "? ", 2);
				if ((save = get_next_line(0)) == NULL)
					return (epured);
				epured = (my_strcat(epured, save));
				a += 1;
				continue;
			}
		}
		if (epured[a] == ' ' && c != 0) {
			epured[a] = '"';
			c = 0;
		}
		a += 1;
	}
	if (epured[a] == '\0' && c == 1) {
		epured[a] = '"';
		epured[a+1] = '\0';
	}
	return (epured);
}
