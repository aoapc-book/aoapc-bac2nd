#include <stdio.h>

int main() {
    int data;
    int min;
    int max;
    int sum = 0;
    int counter = 0;
    while(scanf("%d", &data) == 1) {
        sum += data;
        if (++counter == 1) {
            min = max = data;
        }
        if (data < min) {
            min = data;
        }
        if (data > max) {
            max = data;
        }
    }
    printf("%d, %d, %.2lf", min, max, (float)sum / counter);
    return 0;
}
