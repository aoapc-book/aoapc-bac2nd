#include <stdio.h>
#include <math.h>

int main() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            int num = i * 1100 + j * 11;
            int sqt = floor(sqrt(num) + 0.5);
            if (num == pow(sqt, 2)) {
                printf("%d", num);
            }
        }
    }
    return 0;
}
