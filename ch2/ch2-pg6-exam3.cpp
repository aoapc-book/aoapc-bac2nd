#include <stdio.h>
// #include <math.h>

int main() {
    double sum = 1;
    double entry = 0;
    int i = 1;

    do {
        entry = 1.0 / (i * 2 + 1);
        if (i % 2 == 0) {
            sum += entry;
        } else {
            sum -= entry;
        }
        i++;
    } while (entry > 1e-6);

    printf("%lf\n", sum);
    // printf("%lf\n", M_PI / 4);

    return 0;
}
