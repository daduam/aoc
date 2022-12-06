#include "stdio.h"
#include "string.h"
#include "utils.h"

/**
 * count_unique - Counts unique characters in a string.
 *
 * @window: Null-terminated string.
 * Return: Number of unique characters in @window.
 */
int count_unique(char *window)
{
	int i, count;
	int counter[26] = {0};

	for (i = 0, count = 0; window[i]; i++)
	{
		if (counter[window[i] - 'a'] == 0)
			count++;
		counter[window[i] - 'a'] += 1;
	}
	return (count);
}

/**
 * slide_window - Slides window one place to the left and adds new character.
 *
 * @window: Window.
 * @c: New character.
 */
void slide_window(char *window, char c)
{
	int i;
	int window_size = strlen(window);

	for (i = 1; i < window_size; i++)
		window[i - 1] = window[i];
	window[i - 1] = c;
}

/**
 * solve_d06p1 - solves part 1 of day 6 (Tuning Trouble).
 *
 * Return: Number of characters processed before the first start-of-packet
 *         marker is detected.
 */
int solve_d06p1(void)
{
	char c, window[4];
	int start_of_packet;

	stream_file_to_stdin("input/d06.txt");
	for (start_of_packet = 0; start_of_packet < 4; start_of_packet++)
	{
		c = getchar();
		window[start_of_packet] = c;
	}
	for (; count_unique(window) < 4; start_of_packet++)
	{
		c = getchar();
		if (feof(stdin))
			break;
		slide_window(window, c);
	}
	fclose(stdin);
	return (start_of_packet);
}

/**
 * solve_d06p2 - solves part 2 of day 6 (Tuning Trouble).
 *
 * Return: Number of characters processed before the first start-of-message
 *         marker is detected.
 */
int solve_d06p2(void)
{
	char c, window[14];
	int start_of_message;

	stream_file_to_stdin("input/d06.txt");
	for (start_of_message = 0; start_of_message < 14; start_of_message++)
	{
		c = getchar();
		window[start_of_message] = c;
	}
	for (; count_unique(window) < 14; start_of_message++)
	{
		c = getchar();
		if (feof(stdin))
			break;
		slide_window(window, c);
	}
	fclose(stdin);
	return (start_of_message);
}
