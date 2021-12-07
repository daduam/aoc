#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define POS_MAX 2000
int pos[2000];
long long cost[2000];
char str[5000];
long long min(long long a, long long b) { return a < b ? a : b; }

int main() {
    int i, j, npos = 0;
    scanf("%s", str);
    char *delim = ",";
    char *token = strtok(str, delim);
    while (token) {
        pos[npos++] = atoi(token);
        token = strtok(NULL, delim);
    }
    for (i = 1; i < POS_MAX; i++) {
        cost[i] = cost[i-1] + i;
    }
    long long fuel = 10e16;
    for (i = 0; i <= POS_MAX; i++) {
        long long cur = 0;
        for (j = 0; j < npos; j++) {
            cur += cost[abs(pos[j] - i)];
        }
        fuel = min(fuel, cur);
    }
    printf("Fuel needed: %lld\n", fuel);
}