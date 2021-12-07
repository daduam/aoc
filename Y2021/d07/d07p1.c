#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pos[2000];
char str[5000];
int cmp(const void* a, const void* b) {
    int A = *(const int*)a;
    int B = *(const int*)b;
    return (A > B) - (A < B);
}

int main() {
    int i, npos = 0;
    scanf("%s", str);
    char *delim = ",";
    char *token = strtok(str, delim);
    while (token) {
        pos[npos++] = atoi(token);
        token = strtok(NULL, delim);
    }
    qsort(pos, npos, sizeof(int), cmp);
    int fuel = 0;
    int median = pos[npos/2]; // LAZY
    for (i = 0; i < npos; i++) {
        fuel += abs(pos[i] - median);
    }
    printf("Fuel needed: %d\n", fuel);
}