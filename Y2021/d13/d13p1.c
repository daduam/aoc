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
    scanf("fold along %c=%d", &axis, &d);
    fold_along(axis, d);
    int count = 0;
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            count += grid[i][j];
        }
    }
    printf("Dots after first fold: %d\n", count);
}