#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "d03.h"
#include "utils.h"

/**
 * get_item_priority - Priority of rucksack item.
 *
 * @item: alphabet representing a rucksack item.
 * Return: Items a through z have priorities 1 through 26.
 *         Items A through Z have priorities 27 through 52.
 */
int get_item_priority(char item)
{
	if (islower(item))
		return (item - 'a' + 1);
	if (isupper(item))
		return (item - 'A' + 27);
	return (-1);
}

/**
 * get_priority_for_misplaced_item - Gets priority of item in two compartments.
 *
 * @rucksack: string representing items in rucksack.
 * Return: Priority of item in both compartments or 0 if none.
 */
int get_priority_for_misplaced_item(const char *rucksack)
{
	int i, nitems, first_compartment[52];

	for (i = 0; i < 52; i++)
		first_compartment[i] = 0;
	nitems = strlen(rucksack);
	for (i = 0; i < nitems / 2; i++)
		first_compartment[get_item_priority(rucksack[i]) - 1] += 1;
	for (i = nitems / 2; i < nitems; i++)
		if (first_compartment[get_item_priority(rucksack[i]) - 1])
			return (get_item_priority(rucksack[i]));

	return (0);
}

/**
 * get_priority_for_group - Gets badge priority of three-elf group.
 *
 * @first: rucksack of first elf
 * @second: rucksack of second elf
 * @third: rucksack of third elf
 * Return: Priority of badge of three-elf group or 0 if none.
 */
int get_priority_for_group(
	const char *first, const char *second, const char *third)
{
	int i, j, first_elf[52], second_elf[52];

	for (i = 0; i < 52; i++)
		first_elf[i] = second_elf[i] = 0;
	if (!(first && second && third))
		return (0);
	for (i = 0; i < strlen(first); i++)
		first_elf[get_item_priority(first[i]) - 1] += 1;
	for (i = 0; i < strlen(second); i++)
		second_elf[get_item_priority(second[i]) - 1] += 1;
	for (i = 0; i < strlen(third); i++)
	{
		j = get_item_priority(third[i]);
		if (first_elf[j - 1] && second_elf[j - 1])
			return (j);
	}
	return (0);
}

/**
 * solve_d03p1 - solves part 1 of day 3 (Rucksack Reorganization).
 *
 * Return: Total priorities of misplaced items.
 */
int solve_d03p1(void)
{
	int total_priorities;
	char rucksack[64];

	stream_file_to_stdin("input/d03.txt");
	total_priorities = 0;
	while (scanf("%s", rucksack))
	{
		if (feof(stdin))
			break;
		total_priorities += get_priority_for_misplaced_item(rucksack);
	}
	fclose(stdin);
	return (total_priorities);
}

/**
 * solve_d03p2 - solves part 2 of day 3 (Rucksack Reorganization).
 *
 * Return: Total badge priorities of three-elf groups.
 */
int solve_d03p2(void)
{
	int i, total_priorities;
	char rucksacks[3][64];

	stream_file_to_stdin("input/d03.txt");
	total_priorities = 0;
	while (!feof(stdin))
	{
		for (i = 0; i < 3; i++)
			scanf("%s", rucksacks[i]);
		if (feof(stdin))
			break;
		total_priorities +=
			get_priority_for_group(rucksacks[0], rucksacks[1], rucksacks[2]);
	}
	fclose(stdin);
	return (total_priorities);
}
