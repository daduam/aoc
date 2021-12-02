#include <stdio.h>
#include <string.h>

int main() {
    long long pos = 0, depth = 0, x;
    char dir[10];

    while (1) {
        scanf("%s %lld", dir, &x);
        if(feof(stdin)) {
            printf("Position x Depth: %lld\n", pos * depth);
            break;
        }
        if (strcmp(dir, "forward") == 0) {
            pos += x;
        } else {
            int mul = strcmp(dir, "up") == 0 ? -1 : 1;
            depth += (mul * x);
            // if (strcmp(dir, "up") == 0) {
            //     depth -= x;
            // } else if (strcmp(dir, "down") == 0) {
            //     depth += x;
            // }
        }
    }

    return 0;
}