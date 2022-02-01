#include <bits/stdc++.h>
using namespace std;

int main() {
	string instr;
	getline(cin, instr);
	int count = 0;
	for (char ch : instr) {
		if (ch == '(') {
			count += 1;
		} else {
			count -= 1;
		}
	}
	printf("The instructions  result in floor: %d\n", count);
	return 0;
}
