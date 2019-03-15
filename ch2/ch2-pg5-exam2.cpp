#include <stdio.h>

int main() {
    int numInput = 0;
    scanf("%d", &numInput);

    long long n = numInput;
    int counter = 0;

    while (n > 1) {
        if (n % 2 ==1) {
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
        counter++;
    }
    printf("%d", counter);
    return 0;
}
