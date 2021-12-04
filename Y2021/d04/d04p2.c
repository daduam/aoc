#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char order[5000];
struct board {
    int v; // value
    int m; // isMarked
} boards[200][5][5];
int board_done[200];

int main() {
    int i, j, k, nboards = 0;
    scanf("%s", order);

    while (1) {
        scanf("%d", &boards[nboards][0][0].v);
        if (feof(stdin)) {
            break;
        }
        for (i = 1; i < 5; i++) {
            scanf("%d", &boards[nboards][0][i].v);
        }
        for (i = 1; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                scanf("%d", &boards[nboards][i][j].v);
            }
        }
        nboards++;
    }

    int last_board = -1;
    char *delim = ",";
    char *token = strtok(order, delim);
    while (token) {
        int pick = atoi(token);
        token = strtok(NULL, delim);

        for (i = 0; i < nboards; i++) {
            for (j = 0; j < 5; j++) {
                for (k = 0; k < 5; k++) {
                    if (boards[i][j][k].v == pick) {
                        boards[i][j][k].m = 1;
                    }
                }
            }
            for (j = 0; j < 5; j++) {
                int ok_row = 1;
                int ok_col = 1;
                for (k = 0; k < 5; k++) {
                    ok_row &= boards[i][j][k].m;
                    ok_col &= boards[i][k][j].m;
                }
                if (ok_row || ok_col) {
                    board_done[i] = 1;
                    int done_count = 0;
                    for (k = 0; k < nboards; k++) {
                        done_count += board_done[k];
                    }
                    if (done_count == nboards) {
                        last_board = i;
                        long long sum = 0;
                        for (i = 0; i < 5; i++) {
                            for (j = 0; j < 5; j++) {
                                if (boards[last_board][i][j].m == 0) {
                                    sum += boards[last_board][i][j].v;
                                }
                            }
                        }
                        printf("Unmarked sum of board %d: %lld\n", last_board, sum);
                        printf("Pick: %d\n", pick);
                        printf("Final score: %lld\n", sum * pick);
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}