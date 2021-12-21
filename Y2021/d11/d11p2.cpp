#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> grid;
    string str;
    while (getline(cin, str)) {
        vector<int> cur;
        for (char ch : str) {
            cur.push_back(ch - '0');
        }
        grid.push_back(cur);
    }
    int n = grid.size();
    int m = grid[0].size();
    vector<pair<int, int>> dt = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0},
        {-1, -1}, {1, 1}, {1, -1}, {-1, 1}
    };
    auto is_edge = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    int step = 0;
    while (true) {
        step++;
        int flashes = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j]++;
                if (grid[i][j] > 9) {
                    q.push({i, j});
                    grid[i][j] = 0;
                    flashes++;
                }
            }
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto& d : dt) {
                int x = u.first + d.first;
                int y = u.second + d.second;
                if (is_edge(x, y) && grid[x][y] > 0) {
                    grid[x][y]++;
                    if (grid[x][y] > 9) {
                        grid[x][y] = 0;
                        flashes++;
                        q.push({x, y});
                    }
                }
            }
        }
        if (flashes == n*m) {
            break;
        }
    }
    printf("Flashes sync at step %d.\n", step);
    return 0;
}