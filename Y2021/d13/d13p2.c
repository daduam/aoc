#include <stdio.h>

#define DIM 1500
int grid[DIM][DIM];
void fold_along(char axis, int d) {
    int i, j;
    if (axis == 'x') {
        for (i = 0; i < DIM; i++) {
            for (j = 0; j < d; j++) {
                grid[i][j] = grid[i][j] || grid[i][2*d-j];
                grid[i][2*d-j] = 0;
            }
        }
    } else {
        for (i = 0; i < d; i++) {
            for (j = 0; j < DIM; j++) {
                grid[i][j] = grid[i][j] || grid[2*d-i][j];
                grid[2*d-i][j] = 0;
            }
        }
    }
}

int main() {
    int x, y, d, i, j;
    char axis;
    while (scanf("%d,%d", &y, &x) == 2) {
        grid[x][y] = 1;
    }
    while (1) {
        scanf("fold along %c=%d%*c", &axis, &d);
        if (feof(stdin)) {
            break;
        }
        fold_along(axis, d);
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 50; j++) {
            printf("%c", grid[i][j] ? '#' : ' ');
        }
        puts("");
    }
}