#include <bits/stdc++.h>
using namespace std;

int main() {
    string polymer, str;
    getline(cin, polymer);
    getchar();
    map<string, char> mp;
    while (getline(cin, str)) {
        mp[str.substr(0, 2)] = str[6];
    }
    map<char, long long> cnt;
    cnt[polymer[0]]++;
    map<string, long long> cnt_pairs;
    for (int i = 1; i < (int)polymer.size(); i++) {
        cnt_pairs[polymer.substr(i-1, 2)]++;
        cnt[polymer[i]]++;
    }
    for (int step = 0; step < 10; step++) {
        map<string, long long> cur;
        for (auto p : cnt_pairs) {
            char ch = mp[p.first];
            string s1 = {p.first[0], ch};
            string s2 = {ch, p.first[1]};
            cur[s1] += p.second;
            cur[s2] += p.second;
            cnt[ch] += p.second;
        }
        cnt_pairs = cur;
    }
    long long maxcnt = 0;
    long long mincnt = 1e16;
    for (auto p : cnt) {
        maxcnt = max(maxcnt, p.second);
        mincnt = min(mincnt, p.second);
    }
    printf("Most common - Least common: %lld\n", maxcnt - mincnt);
    return 0;
}
