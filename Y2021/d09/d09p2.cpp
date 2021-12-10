#include <bits/stdc++.h>
using namespace std;

int hmap[200][200];
int seen[200][200];
struct LowPoint {
    int x;
    int y;
    int basin_size;
};

int main() {
    int n = 0;
    int m = 0;
    string str;
    while (getline(cin, str)) {
        m = str.size();
        for (int i = 0; i < m; i++) {
            hmap[n][i] = str[i] - '0';
        }
        n++;
    }
    auto is_valid = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<LowPoint> lowpts;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int is_lowpt = 1;
            for (int k = 0; k < 4; k++) {
                int x = i + d[k][0];
                int y = j + d[k][1];
                if (is_valid(x, y) && (hmap[x][y] <= hmap[i][j])) {
                    is_lowpt = 0;
                }
            } 
            if (is_lowpt) {
                lowpts.push_back({i, j, 0});
            }
        }
    }
    for (auto &pt: lowpts) {
        queue<pair<int, int>> q;
        q.push({pt.x, pt.y});
        seen[pt.x][pt.y] = 1;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            pt.basin_size += 1;
            for (int k = 0; k < 4; k++) {
                int x = u.first + d[k][0];
                int y = u.second + d[k][1];
                bool valid = is_valid(x, y) && hmap[x][y] > hmap[u.first][u.second];
                if (valid && hmap[x][y] != 9 && seen[x][y] != 1) {
                    seen[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
    }
    sort(lowpts.begin(), lowpts.end(), [](LowPoint a, LowPoint b) {
        return a.basin_size > b.basin_size;
    });
    long long answer = 1;
    for (int i = 0; i < 3; i++) {
        answer *= lowpts[i].basin_size;
    }
    printf("Product of basins: %lld\n", answer);
    return 0;
}
