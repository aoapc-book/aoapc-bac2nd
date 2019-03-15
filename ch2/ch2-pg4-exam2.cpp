#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    int counter = 0;
    while (n > 1) {
        if (n % 2 == 1) {
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
        counter++;
    }
    printf("%d", counter);
    return 0;
}
