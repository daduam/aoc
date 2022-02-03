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
	set<pair<int, int>> locations;
	auto visit = [&](int steps, int dx, int dy) {
		for (int i = 0; i < steps; i++) {
			xpos += dx;
			ypos += dy;
			if (locations.count({xpos, ypos})) {
				return true;
			}
			locations.insert({xpos, ypos});
		}
		return false;
	};
	char *token = strtok(instr, delim);
	while (token) {
		facing = next_facing(token[0]);
		int steps = atoi(token + 1);
		if (facing == north) {
			if (visit(steps, -1, 0)) {
				break;
			}
		} else if (facing == south) {
			if (visit(steps, 1, 0)) {
				break;
			}
		} else if (facing == east) {
			if (visit(steps, 0, -1)) {
				break;
			}
		} else {
			if (visit(steps, 0, 1)) {
				break;
			}
		}
		token = strtok(NULL, delim);
	}
	int blocks = abs(xpos) + abs(ypos);
	printf("The first location you visit twice is %d blocks away\n", blocks);
	return 0;
}
