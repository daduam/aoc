#include <bits/stdc++.h>
using namespace std;

int main() {
	char instr[1000];
	scanf("%[^\n]", instr);
	const char* delim = ", ";
	int xpos = 0;
	int ypos = 0;
	enum direction { north, south, east, west };
	int facing = north;
	auto next_facing = [&](char turn) {
		if (facing == north) {
			return turn == 'L' ? east : west;
		} else if (facing == south) {
			return turn == 'L' ? west : east;
		} else if (facing == west) {
			return turn == 'L' ? north : south;
		} else {
			return turn == 'L' ? south : north;
		}
	};
	char *token = strtok(instr, delim);
	while (token) {
		facing = next_facing(token[0]);
		int steps = atoi(token + 1);
		if (facing == north) {
			xpos -= steps;
		} else if (facing == south) {
			xpos += steps;
		} else if (facing == east) {
			ypos -= steps;
		} else {
			ypos += steps;
		}
		token = strtok(NULL, delim);
	}
	int blocks = abs(xpos) + abs(ypos);
	printf("Easter Bunny HQ is %d blocks away\n", blocks);
	return 0;
}
