/*
** EPITECH PROJECT, 2018
** quotes
** File description:
** gaspacho andalou
*/

#include "my.h"
#include <string.h>

# define my_strndup strndup
# define my_strdup strdup
# define my_strlen strlen

int	check_str(char c, char *str)
{
	int	i = 0;

	while (str[++i] != 0) {
		if (str[i] == c)
			return (str[i] = '&' ? i : i);
	}
	return (-1);
}

char	**parse_quote(char *str)
{
	int	i = -1;
	int	j = -1;
	char	**tab = NULL;
	char	c = 0;
	int	help = -1;
	int	k = 0;

	if ((tab = malloc(sizeof(char *) * 10000)) == NULL)
		return (NULL);
	while (str[++i] != 0) {
		if (i > help && (str[i] == '"' || str[i] == '\'')) {
			c = str[i];
			if ((help = check_str(c, &str[i])) == -1) {
				printf("Unmatched '%c'.\n", c);
				return (NULL);
			}
			c = 0;
		}
	}
	return (tab);
}

int	main()
{
	char	*s = NULL;
	
	while ("gaspacho andalou") {
		s = gnl(0);
		if (parse_quote(s) == NULL) {
			printf("Unmatched.\n");
		}
		printf("No worries mate it's good!\n");
	}
	return (0);
}
