#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define AFTER 256
char str[1000];
long long previous[10];
long long cur[10];

int main() {
    int day, i;
    scanf("%s", str);
    const char *delim = ",";
    char *token = strtok(str, delim);
    while (token) {
        cur[atoi(token)]++;
        token = strtok(NULL, delim);
    }
    for (day = 1; day <= AFTER; day++) {
        for (i = 0; i <= 8; i++) {
            if (i == 0) {
                previous[6] += cur[i];
                previous[8] = cur[i];
            } else {
                previous[i-1] += cur[i];
            }
        }
        for (int i = 0; i <= 8; i++) {
            cur[i] = previous[i];
            previous[i] = 0;
        }
    }
    long long count = 0;
    for (int i = 0; i <= 8; i++) {
        count += cur[i];
    }
    printf("Lanternfish after %d days: %lld\n", AFTER, count);
}