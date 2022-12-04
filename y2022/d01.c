#include "stdio.h"
#include "stdlib.h"
#include "utils.h"

/**
 * solve_d01p1 - solves part 1 of day 1 (Calorie Counting).
 *
 * Return: Totals calories carried by elf carrying highest calories.
 */
int solve_d01p1(void)
{
	char s[15];
	int current_elf_calories, max_calories;

	stream_file_to_stdin("input/d01.txt");
	max_calories = 0;
	while (!feof(stdin))
	{
		current_elf_calories = 0;
		while (scanf("%[^\n]*c", s))
		{
			if (feof(stdin))
				break;
			getchar();
			current_elf_calories += atoi(s);
		}
		getchar();
		if (current_elf_calories > max_calories)
			max_calories = current_elf_calories;
	}
	fclose(stdin);
	return (max_calories);
}

/**
 * update_top_three - Replaces smallest between @a, @b, and @c with @calories.
 *
 * @a: int
 * @b: int
 * @c: int
 * @calories: int
 */
void update_top_three(int *a, int *b, int *c, int calories)
{
	if (calories >= *a && *a <= *b && *a <= *c)
		*a = calories;
	else if (calories >= *b && *b <= *a && *b <= *c)
		*b = calories;
	else if (calories >= *c && *c <= *a && *c <= *b)
		*c = calories;
}

/**
 * solve_d01p2 - solves part 2 of day 1 (Calorie Counting).
 *
 * Return: Sum of calories carried by top three elfs carrying the most calries.
 */
int solve_d01p2(void)
{
	char s[15];
	int current_elf_calories, top_a, top_b, top_c;

	stream_file_to_stdin("input/d01.txt");
	top_a = top_b = top_c = 0;
	while (!feof(stdin))
	{
		current_elf_calories = 0;
		while (scanf("%[^\n]*c", s))
		{
			if (feof(stdin))
				break;
			getchar();
			current_elf_calories += atoi(s);
		}
		getchar();
		update_top_three(&top_a, &top_b, &top_c, current_elf_calories);
	}
	fclose(stdin);
	return (top_a + top_b + top_c);
}
