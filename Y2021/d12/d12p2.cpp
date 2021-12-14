#include <bits/stdc++.h>
using namespace std;

int main() {
    int start_pos = -1;
    int end_pos = -1;
    vector<bool> sm;
    map<string, int> mp;
    map<int, vector<int>> adj;
    string str;
    while (getline(cin, str)) {
        int pos = str.find('-');
        string u = str.substr(0, pos);
        if (!mp.count(u)) {
            mp[u] = sm.size();
            sm.push_back(islower(u[0]));
        }
        string v = str.substr(pos+1);
        if (!mp.count(v)) {
            mp[v] = sm.size();
            sm.push_back(islower(v[0]));
        }
        adj[mp[u]].push_back(mp[v]);
        adj[mp[v]].push_back(mp[u]);
        start_pos = u == "start" ? mp[u] : v == "start" ? mp[v] : start_pos;
        end_pos = u == "end" ? mp[u] : v == "end" ? mp[v] : end_pos;
    }
    int paths = 0;
    bool wildcard_used = false; // visited one small cave twice already
    vector<int> seen(sm.size(), 0);
    function<void(int)> dfs = [&](int u) {
        seen[u]++;
        wildcard_used = wildcard_used || (sm[u] && seen[u] == 2);
        for (int v: adj[u]) {
            if (v == start_pos) {
                continue;
            }
            if (v == end_pos) {
                paths++;
                continue;
            }
            if (!sm[v] || seen[v] == 0 || (seen[v] == 1 && !wildcard_used)) {
                dfs(v);
            }
        }
        if (sm[u] && seen[u] == 2) {
            wildcard_used = false;
        }
        seen[u]--;
    };
    dfs(start_pos);
    printf("Paths: %d\n", paths);
}