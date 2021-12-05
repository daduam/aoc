#include <stdio.h>

#define N_GRID 2000
int grid[N_GRID][N_GRID];
int max(int a, int b) { return (a >= b ? a : b); }
int min(int a, int b) { return (a <= b ? a : b); }
struct pos { int x; int y; };

int main() {
    int a, b, c, d, i, j;
    while (1) {
        scanf("%d,%d -> %d,%d", &a, &b, &c, &d);
        if (feof(stdin)) {
            break;
        }
        if (a == c) {
            for (i = min(b,d); i <= max(b,d); i++) {
                grid[i][a]++;
            }
        } else if (b == d) {
            for (j = min(a,c); j <= max(a,c); j++) {
                grid[b][j]++;
            }
        } else {
            int diff = max(a,c) - min(a,c);
            // position of first point
            if (b < d) {
                int top_left = a < c;
                for (i = 0; i <= diff; i++) {
                    if (top_left) {
                        grid[b+i][a+i]++;
                    } else {
                        grid[b+i][a-i]++;
                    }
                }
            } else {
                int bottom_left = a < c;
                for (i = 0; i <= diff; i++) {
                    if (bottom_left) {
                        grid[b-i][a+i]++;
                    } else {
                        grid[b-i][a-i]++;
                    }
                }
            }
        }
    }
    int answer = 0;
    for (i = 0; i < N_GRID; i++) {
        for (j = 0; j < N_GRID; j++) {
            if (grid[i][j] > 1) {
                answer++;
            }
        }
    }
    printf("Lines overlap at %d points\n", answer);

    return 0;
}