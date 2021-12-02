#include <stdio.h>

int main() {
    int a, b, c, d, prev, cur, count = 0;
    scanf("%d %d %d", &a, &b, &c);

    prev = a + b + c;
    while(1) {
        scanf("%d", &d);
        if (feof(stdin)) {
            printf("%d depth measurement increases.\n", count);
            break;
        }
        cur = b + c + d;
        a = b;
        b = c;
        c = d;
        if (cur > prev) {
            count++;
        }
        prev = cur;
    }
    
    return 0;
}