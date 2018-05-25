/*
** EPITECH PROJECT, 2018
** word array with word in param
** File description:
** for parsing
*/

#include "../../include/my_sh.h"
/*
int	find_word(char *str, char *word)
{
	int	i = 0;
	int	n = 0;

	while (str[i] != '\0') {
		if (strncmp(&str[i], word, strlen(word)) == 0) {
			i += strlen(word);
			n += 1;
		}
		i += 1;
	}
	return (n);
}

char	**word_array_with_word(char *str, char *word)
{
	int	n_word = find_word(str, word);
	char	**tab = malloc(sizeof(char *) * (n_word * n_word + 1) + sizeof(char *));
	int	j = -1;
	int	i = 0;
	int	k = 0;

	while (str[++i] != '\0') {
		if (str[i] == '&') {
			str[i] = '\0';
			printf("&str[%d] = %s\n", k, &str[k]);
			while (str[i] == '&')
				i++;
			str[i] = '\0';
			i  += 1;
//	printf("&str[%d] = %s\n", k, &str[k]);
			k = i + 1;
		}
	}
	if (str[i - 1] != '\0')
		printf("&str[%d] = %s\n", k, &str[k]);
}

void	main(void)
{
	char	*str = strdup("ls && salut && ls && cd");
	word_array_with_word(str, "&&");
}
*/
