#include <bits/stdc++.h>
using namespace std;

int main() {
    int score = 0;
    vector<char> open = {'(', '[', '{', '<'};
    map<char, int> scores = {{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};
    auto is_pair = [](char a, char b) {
        return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}') || (a == '<' && b == '>');
    };
    string str;
    while (getline(cin, str)) {
        stack<char> st;
        for (char ch : str) {
            if (find(open.begin(), open.end(), ch) != end(open)) {
                st.push(ch);
            } else if (is_pair(st.top(), ch)) {
                st.pop();
            } else {
                score += scores[ch];
                break;
            }
        }
    }
    printf("Total syntax error score: %d\n", score);
    return 0;
}