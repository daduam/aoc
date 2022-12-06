#include "stdio.h"
#include "aoc.h"

/**
 * main - Run tests for day here.
 *
 * Return: 0 on success.
 */
int main(void)
{
	printf("[d1p1] Most calories: %d\n", solve_d01p1());
	printf("[d1p2] Sum of top three calories: %d\n", solve_d01p2());

	printf("[d2p1] Total score using player choices: %d\n", solve_d02p1());
	printf("[d2p2] Total score using round outcomes: %d\n", solve_d02p2());

	printf("[d3p1] Total priorities of misplaced items: %d\n", solve_d03p1());
	printf("[d3p2] Total badge priorities of three-elf groups: %d\n",
		   solve_d03p2());

	printf("[d6p1] Characters processed before start-of-packet marker: %d\n",
		   solve_d06p1());
	printf("[d6p2] Characters processed before start-of-message marker: %d\n",
		   solve_d06p2());

	return (0);
}
