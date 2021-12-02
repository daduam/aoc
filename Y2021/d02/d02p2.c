#include <stdio.h>
#include <string.h>

int main() {
    long long pos = 0, depth = 0, aim = 0, x;
    char dir[10];

    while (1) {
        scanf("%s %lld", dir, &x);
        if(feof(stdin)) {
            printf("Position x Depth: %lld\n", pos * depth);
            break;
        }
        if (strcmp(dir, "forward") == 0) {
            pos += x;
            depth += aim * x;
        } else {
            int mul = strcmp(dir, "up") == 0 ? -1 : 1;
            aim += (mul * x);
        }
    }

    return 0;
}