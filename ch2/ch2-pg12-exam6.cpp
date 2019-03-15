#include <stdio.h>

int main() {
    int data;
    int counter;
    int kase = 1;

    while(scanf("%d", &counter) == 1 && counter) {
        int sum = 0;
        int min = (unsigned int)(~0) >> 1;
        int max = min + 1;
        for (int i = 1; i <= counter; i++) {
            scanf("%d", &data);
            sum += data;
            if (data < min) {
                min = data;
            }
            if (data > max) {
                max = data;
            }
        }
        if (kase > 1) {
            printf("\n");
        }
        printf("Case %d: min=%d, max=%d, avg=%.3lf\n", kase++, min, max, (double) sum / counter);
    } 
    return 0;
}
