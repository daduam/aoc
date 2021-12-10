#include <stdio.h>
#include <string.h>

int hmap[200][200];
char str[200];
int is_valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    int n = 0, m = 0, i, j, k;
    int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    while (1) {
        scanf("%s", str);
        if (feof(stdin)) {
            break;
        }
        m = strlen(str);
        for (i = 0; i < m; i++) {
            hmap[n][i] = str[i] - '0';
        }
        n += 1;
    }
    long long sum_risk_level = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            int is_low_point = 1;
            for (k = 0; k < 4; k++) {
                int x = i + d[k][0];
                int y = j + d[k][1];
                if (is_valid(x, y, n, m) && (hmap[x][y] <= hmap[i][j])) {
                    is_low_point = 0;
                }
            }    
            if (is_low_point) {
                sum_risk_level += 1 + hmap[i][j];
            }
        }
    }
    printf("Sum risk level: %lld\n", sum_risk_level);
    return 0;
}
