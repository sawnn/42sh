/*
** EPITECH PROJECT, 2018
** error sig
** File description:
** gaspacho andalou
*/

#include "my.h"

void	check_segfault(int z)
{
	if (WTERMSIG(z) == 6) {
		write(1, "Abort", 5);
		WCOREDUMP(z) ? write(1, " (core dumped)", 13) : 0;
		write(1, "\n", 1);
		call_exit(134);
		return;
	} if (WTERMSIG(z) == 8) {
		write(1, "Floating exception", 18);
		WCOREDUMP(z) ? write(1, " (core dumped)", 13) : 0;
		write(1, "\n", 1);
		call_exit(136);
		return;
	} if (WTERMSIG(z) == 11) {
		write(1, "Segmentation fault", 18);
		WCOREDUMP(z) ? write(1, " (core dumped)", 13) : 0;
		write(1, "\n", 1);
		call_exit(139);
		return;
	}
	call_exit(z/ 256);
}
