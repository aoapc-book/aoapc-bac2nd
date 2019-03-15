#include <stdio.h>
#include <time.h>

int main() {
    const int MOD = 1000000;
    int n = 0;
    int sum = 0;

    scanf("%d", &n);
    if (n >= 25) {
        n = 24;
    }


    for  (int i = 1; i <= n; i++) {
        int factorial = 1;
        for (int j = 1; j <= i; j++) {
            factorial = (factorial * j) % MOD;
        }
        sum = (sum + factorial) % MOD;
    }

    printf("%d\n", sum);
    printf("Process seconds: %.10f\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
