#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define AFTER 80
char str[1000];
long long prev[10];
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
                prev[6] += cur[i];
                prev[8] = cur[i];
            } else {
                prev[i-1] += cur[i];
            }
        }
        for (i = 0; i <= 8; i++) {
            cur[i] = prev[i];
            prev[i] = 0;
        }
    }
    long long count = 0;
    for (i = 0; i <= 8; i++) {
        count += cur[i];
    }
    printf("Lanternfish after %d days: %lld\n", AFTER, count);
}