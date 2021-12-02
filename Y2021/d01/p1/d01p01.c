#include <stdio.h>

int main() {
    int prev, cur, count = 0;
    scanf("%d", &prev);

    while(1) {
        scanf("%d", &cur);
        if (feof(stdin)) {
            printf("%d depth measurement increases.\n", count);
            break;
        }
        if (cur > prev) {
            count++;
        }
        prev = cur;
    }
    
    return 0;
}