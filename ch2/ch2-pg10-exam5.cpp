#include <stdio.h>

int main() {
    int num;
    int sum = 0;
    int counter = 0;
    int min = (unsigned int)(~0) >> 1;
    int max = (unsigned int)(1) << 31;


#ifdef LOCAL
    freopen("data/ch2-pg10-exam5.in", "r", stdin);
    freopen("data/ch2-pg10-exam5.out", "w", stdout);
#endif

    while(scanf("%d", &num) == 1) {
        sum += num;
        counter++;
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
    }
    printf("%d, %d, %.2lf\n", min, max, (double)sum / counter);
    return 0;
}
