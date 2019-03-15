#include <stdio.h>

int main() {
    printf("ch2-pg15-exer3 Reverise Triangle.\n");
    int n;
    scanf("%d", &n);
    if (n > 20) {
        n = 20;
    }
    const int maxWidth = n;

    while (n >= 1) {
        for (int i = 1; i <= maxWidth - n; ++i) {
            printf(" ");
        }
        for (int j = 1; j <= 2 * n - 1; ++j) {
            printf("*");
        }
        printf("\n");
        n--;
    }
    return 0;
}
