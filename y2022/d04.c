#include "stdio.h"
#include "utils.h"

/**
 * check_full_overlap - Checks if either range is fully contained in the other.
 *
 * @ra: Left of first range.
 * @rb: Right of first range.
 * @ta: Left of second range.
 * @tb: Right of second range.
 * Return: Non-zero if first range is fully contained in second range, or
 *         if second range is fully contained in the first.
 */
int check_full_overlap(int ra, int rb, int ta, int tb)
{
	return ((ra <= ta && rb >= tb) || (ta <= ra && tb >= rb));
}

/**
 * check_overlap - Checks if two ranges overlap at all.
 *
 * @ra: Left of first range.
 * @rb: Right of first range.
 * @ta: Left of second range.
 * @tb: Right of second range.
 * Return: Non-zero integer if the two ranges overlap.
 */
int check_overlap(int ra, int rb, int ta, int tb)
{
	return ((ra <= ta && rb >= ta) ||
			(rb >= tb && ra <= tb) ||
			check_full_overlap(ra, rb, ta, tb));
}

/**
 * solve_d04p1 - solves part 1 of day 4 (Camp Cleanup).
 *
 * Return: Number of assignment pairs which have one range
 *         fully containing the other.
 */
int solve_d04p1(void)
{
	int ra, rb, ta, tb, overlaps;

	stream_file_to_stdin("input/d04.txt");
	overlaps = 0;
	while (scanf("%d-%d,%d-%d", &ra, &rb, &ta, &tb))
	{
		if (feof(stdin))
			break;
		if (check_full_overlap(ra, rb, ta, tb))
			overlaps += 1;
	}
	fclose(stdin);
	return (overlaps);
}

/**
 * solve_d04p2 - solves part 2 of day 4 (Camp Cleanup).
 *
 * Return: Number of assignment pairs which have overlapping ranges.
 */
int solve_d04p2(void)
{
	int ra, rb, ta, tb, overlaps;

	stream_file_to_stdin("input/d04.txt");
	overlaps = 0;
	while (scanf("%d-%d,%d-%d", &ra, &rb, &ta, &tb))
	{
		if (feof(stdin))
			break;
		if (check_overlap(ra, rb, ta, tb))
			overlaps += 1;
	}
	fclose(stdin);
	return (overlaps);
}
