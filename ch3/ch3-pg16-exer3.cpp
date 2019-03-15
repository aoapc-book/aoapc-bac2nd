#include<stdio.h>

int main() {
    printf("Digit Counting, ACM/ICPC Danang 2007, UVa1225\n");
    int counter[10] = {0};
    int n = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        int temp = i;
        while (temp > 0) {
            counter[temp % 10]++;
            temp /= 10;
        }
    }

    printf("[%d", counter[0]);
    for (int i = 1; i < 10; ++i) {
        printf("\t%d", counter[i]);
    }
    printf("]\n");
    return 0;
}
