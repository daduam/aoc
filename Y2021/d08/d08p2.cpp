#include <bits/stdc++.h>
using namespace std;

set<char> to_charset(string s) {
    return set<char>(s.begin(), s.end());
}
int count_same(string a, string b) {
    int count = 0;
    auto charset = to_charset(a);
    for (char ch : b) {
        if (charset.count(ch)) {
            count++;
        }
    }
    return count;
}

int main() {
    int answer = 0;
    string str;
    while (getline(cin, str)) {
        char* token = strtok((char*)str.c_str(), " ");
        map<int, vector<string>> signal_patterns;
        string digits[11];
        vector<string> len_five, len_six;
        for (int i = 0; i < 10; i++) {
            int n = strlen(token);
            if (n == 2) digits[1] = token;
            else if (n == 3) digits[7] = token;
            else if (n == 4) digits[4] = token;
            else if (n == 5) len_five.push_back(token);
            else if (n == 6) len_six.push_back(token);
            else digits[8] = token;
            token = strtok(NULL, " ");
        }
        token = strtok(NULL, " ");
        vector<string> output_value;
        for (int i = 0; i < 4; i++) {
            output_value.emplace_back(token);
            token = strtok(NULL, " ");
        }
        for (string s : len_six) {
            if (count_same(s, digits[4]) == 4) {
                digits[9] = s;
                break;
            }
        }
        for (string s : len_six) {
            if (s != digits[9] && count_same(s, digits[7]) == 3) {
                digits[0] = s;
                break;
            }
        }
        for (string s : len_six) {
            if (s != digits[9] && s != digits[0]) {
                digits[6] = s;
                break;
            }
        }
        for (string s : len_five) {
            if (count_same(s, digits[7]) == 3) {
                digits[3] = s;
                break;
            }
        }
        for (string s : len_five) {
            if (s != digits[3] && count_same(s, digits[6]) == 5) {
                digits[5] = s;
                break;
            }
        }
        for (string s : len_five) {
            if (s != digits[3] && s != digits[5]) {
                digits[2] = s;
                break;
            }
        }
        string val = "";
        for (string s : output_value) {
            auto sset = to_charset(s);
            for (int i = 0; i < 10; i++) {
                if (sset == to_charset(digits[i])) {
                    val += '0' + i;
                    break;
                }
            }
        }
        answer += stoi(val);
    }
    printf("Sum of output values: %d\n", answer);
    return 0;
}