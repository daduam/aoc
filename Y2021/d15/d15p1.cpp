#include <bits/stdc++.h>
using namespace std;

#define INF 10000000
int w[110][110];

int main() {
    int n = 0;
    int m = 0;
    string str;
    while (getline(cin, str)) {
        m = 0;
        for (char ch : str) {
            w[n][m++] = ch - '0';
        }
        n++;
    }
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<int>> d(n, vector<int>(m, INF));
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, 0}});
    d[0][0] = 0;
    auto is_valid = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();
        int ux = u.second.first;
        int uy = u.second.second;
        for (auto k : dir) {
            int x = k.first + ux;
            int y = k.second + uy;
            if (is_valid(x, y) && d[x][y] > d[ux][uy] + w[x][y]) {
                d[x][y] = d[ux][uy] + w[x][y];
                pq.push({-d[x][y], {x, y}});
            }
        }
    }
    printf("Lowest total risk: %d\n", d[n-1][m-1]);
}