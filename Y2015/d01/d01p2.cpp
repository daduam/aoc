#include <bits/stdc++.h>
using namespace std;

int main() {
	string instr;
	getline(cin, instr);
	int count = 0;
	int position = 1;
	for (char ch : instr) {
		if (ch == '(') {
			count += 1;
		} else {
			count -= 1;
		}
		
		if (count == -1) {
			break;
		}
		position++;
	}
	printf("Santa first enters the basement at position: %d\n", position);
	return 0;
}
