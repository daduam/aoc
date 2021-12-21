#include <stdio.h>
#include <string.h>

char str[200];

int main() {
    int count = 0;
    while (!feof(stdin)) {
        scanf("%[^\n]%*c", str);
        char* token = strtok(str, "|");
        token = strtok(NULL, "|");
        token = strtok(token, " ");
        while (token) {
            int n = strlen(token);
            if (n == 2 || n == 3 || n == 4 || n == 7) {
                count++;
            }
            token = strtok(NULL, " ");
        }
    }
    printf("Digits 1, 4, 7, and 8 appears %d times.\n", count);
    return 0;
}
