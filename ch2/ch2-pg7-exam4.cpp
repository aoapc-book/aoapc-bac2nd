#include <stdio.h>

int main() {
    int sum = 0;
    int n = 0;
    const int MOD = 1000000;

    scanf("%d", &n);


    for (int i = 1; i <= n; i++) {
        int factorial = 1;
        for (int j = 1; j <= i; j++) {
            factorial *= j;
        }
        sum += factorial;
    }

    printf("%d\n", sum % MOD);
    return 0;
}
