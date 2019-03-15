#include <stdio.h>

int main() {
    printf("Subsequence ch2-pg16-exer4.cpp\n");
    int n;
    int m;

    while (scanf("%d%d", &n, &m) == 2 && n != 0 && m != 0) {
        float s = 0;
        for (long i = n; i <= m; i++) {
            s += 1.0 / (i * i);
        }
        printf("%.5f\n", s);
    }
    return 0;
}
