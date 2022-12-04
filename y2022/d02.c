#include "stdio.h"
#include "string.h"
#include "utils.h"

/**
 * get_score_for_round - Calculates round score.
 *
 * @player: Player choice (X - rock, Y - paper, Z - scissors).
 * @opponent: Opponent choice (A - rock, Y - paper, Z - scissors).
 * Return: Player score for the round.
 */
int get_score_for_round(char player, char opponent)
{
	int score = 0;

	if (!(strchr("XYZ", player) && strchr("ABC", opponent)))
		return (-1);

	if (player == 'X')
	{
		score += 1;
		if (opponent == 'C')
			score += 6;
		else if (opponent == 'A')
			score += 3;
	}
	else if (player == 'Y')
	{
		score += 2;
		if (opponent == 'A')
			score += 6;
		else if (opponent == 'B')
			score += 3;
	}
	else
	{
		score += 3;
		if (opponent == 'B')
			score += 6;
		else if (opponent == 'C')
			score += 3;
	}

	return (score);
}

/**
 * get_score_for_round_with_outcome - Calculates round score.
 *
 * @outcome: Round outcome for player (X - lose, Y - draw, Z - win).
 * @opponent: Opponent choice (A - rock, Y - paper, Z - scissors).
 * Return: Player score for the round.
 */
int get_score_for_round_with_outcome(char outcome, char opponent)
{
	if (!(strchr("XYZ", outcome) && strchr("ABC", opponent)))
		return (-1);

	if (outcome == 'X')
	{
		if (opponent == 'A')
			return (get_score_for_round('Z', opponent));
		else if (opponent == 'B')
			return (get_score_for_round('X', opponent));
		else
			return (get_score_for_round('Y', opponent));
	}
	else if (outcome == 'Y')
	{
		if (opponent == 'A')
			return (get_score_for_round('X', opponent));
		else if (opponent == 'B')
			return (get_score_for_round('Y', opponent));
		else
			return (get_score_for_round('Z', opponent));
	}
	else
	{
		if (opponent == 'A')
			return (get_score_for_round('Y', opponent));
		else if (opponent == 'B')
			return (get_score_for_round('Z', opponent));
		else
			return (get_score_for_round('X', opponent));
	}
}

/**
 * solve_d02p1 - solves part 1 of day 2 (Rock Paper Scissors).
 *
 * Return: Total scores if the second column is player choice.
 */
int solve_d02p1(void)
{
	int total_score;
	char opponent, player;

	stream_file_to_stdin("input/d02.txt");
	total_score = 0;
	while (scanf("%c %c", &opponent, &player))
	{
		getchar();
		if (feof(stdin))
			break;
		total_score += get_score_for_round(player, opponent);
	}
	fclose(stdin);
	return (total_score);
}

/**
 * solve_d02p2 - solves part 2 of day 2 (Rock Paper Scissors).
 *
 * Return: Total scores if the second column is round outcome.
 */
int solve_d02p2(void)
{
	int total_score;
	char opponent, outcome;

	stream_file_to_stdin("input/d02.txt");
	total_score = 0;
	while (scanf("%c %c", &opponent, &outcome))
	{
		getchar();
		if (feof(stdin))
			break;
		total_score += get_score_for_round_with_outcome(outcome, opponent);
	}
	fclose(stdin);
	return (total_score);
}
