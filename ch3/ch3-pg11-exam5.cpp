#include <stdio.h>

#define MAX_SIZE 100000

int generator[MAX_SIZE + 1];

int main() {
    printf("UVa1583 Digit Generator Another way!\n");

    for (int i = 0; i <= MAX_SIZE; ++i) {
        int sum = i;
        int x = i;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        if (sum <= MAX_SIZE && generator[sum] == 0) {
            generator[sum] = i;
        }
    }
    int n;
    while (scanf("%d", &n) == 1) {
        if (n <= MAX_SIZE) {
            printf("%d\n", generator[n]);
        } else {
            printf("Please input a number not larger than %d!\n", MAX_SIZE);
        }
    }
    return 0;
}
