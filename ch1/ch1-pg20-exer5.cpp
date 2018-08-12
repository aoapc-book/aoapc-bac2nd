#include<stdio.h>

int main() {
    const int SP = 95;
    const int DS = 300;
    const float DIS = 0.85;

    int n;
    scanf("%d", &n);

    if (n * SP >= DS) {
        printf("The pament is: %.3lf\n", n * SP * DIS);
        return 0;
    }
    printf("The pament is: %d\n", n * SP);
    return 0;
}
