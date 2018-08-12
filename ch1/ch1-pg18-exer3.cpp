#include<stdio.h>

int main() {
    int n;
    long sum;
    scanf("%d", &n);

    sum = n * (1 + n) / 2;
    printf("%ld\n", sum);
}
