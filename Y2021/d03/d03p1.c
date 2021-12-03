#include <stdio.h>
#include <string.h>

#define N_64 64

long long freq1[N_64];
long long pow_2[N_64];
char bstr[N_64];

int main() {
    int nbstr = 0, n, i, j, max_n = 0;
    
    pow_2[0] = 1;
    for (i = 1; i < N_64; i++) {
        pow_2[i] = 2 * pow_2[i-1];
    }

    while(1) {
        scanf("%s", bstr);
        if (feof(stdin)) {
            long long gr = 0, epsr = 0;
            for (i = 0; i < max_n; i++) {
                long long mul = freq1[i] > (nbstr/2);
                gr += mul * pow_2[i];
                epsr += (mul ^ 1) * pow_2[i];
            }
            printf("Gamma rate: %lld\n", gr);
            printf("Epsilon rate: %lld\n", epsr);
            printf("Power consumption: %lld\n", gr * epsr);
            break;
        }
        nbstr++;
        n = strlen(bstr);
        if (n > max_n) {
            max_n = n;
        }
        for (i = n-1, j = 0; i >= 0; i--, j++) {
            if(bstr[i] == '1') {
                freq1[j]++;
            }
        }
    }
}