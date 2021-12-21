#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> scores;
    vector<char> open = {'(', '[', '{', '<'};
    auto is_open = [&open](char ch) {
       return find(open.begin(), open.end(), ch) != end(open);
    };
    auto is_pair = [](char a, char b) {
        return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}') || (a == '<' && b == '>');
    };
    string str;
    while (getline(cin, str)) {
        long long cur_score = 0;
        stack<char> st;
        bool incomplete = true;
        for (char ch : str) {
            if (is_open(ch)) {
                st.push(ch);
            } else if (is_pair(st.top(), ch)) {
                st.pop();
            } else {
                incomplete = false;
                break; // corrupted line
            }
        }
        if (!incomplete) {
            continue;
        }
        while (!st.empty()) {
            char ch = st.top();
            st.pop();
            cur_score *= 5;
            if (ch == '(') {
                cur_score += 1;
            } else if (ch == '[') {
                cur_score += 2;
            } else if (ch == '{') {
                cur_score += 3;
            } else {
                cur_score += 4;
            }
        }
        scores.push_back(cur_score);
    }
    sort(scores.begin(), scores.end());
    printf("Middle score: %lld\n", scores[scores.size()/2]);
    return 0;
}