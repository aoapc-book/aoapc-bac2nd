#include<stdio.h>

int main() {

    int fahrenheit;
    float celsius;

    scanf("%d", &fahrenheit);

    celsius = 5 * (fahrenheit - 32) / 9.0;

    printf("%.3lf\n", celsius);

    return 0;
}
