#include <stdio.h>
#include <math.h>

int main() {
    int n;
    const double PI = acos(-1);
    scanf("%d", &n);

    printf("The value of sin(n) is: %.3f\n", sin(PI * n / 180));
    printf("The value of cos(n) is: %.3f\n", cos(PI * n / 180));

    return 0;
}
