#include <stdio.h>

int main() {
    printf("Print the value of 2,4,6,...,2n\n");
    int n;
    scanf("%d", &n);

    for (int i = 2; i <= n * 2; i += 2) {
        // printf("%d\n", i * 2);
        printf("%d\n", i);
    }
    return 0;
}
