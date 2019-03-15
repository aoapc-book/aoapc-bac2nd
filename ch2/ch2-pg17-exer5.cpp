#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Decimal ch2-pg17-exer5.cpp\n");

    int a;
    int b;
    int c;

    while(scanf("%d%d%d", &a, &b, &c) == 3 && (a != 0 || b != 0 || c != 0)) {
        float r = 1.0 * a / b;
        char *rChars;
        gcvt(r, c, rChars);
        printf("%s\n", rChars);
    }
    return 0;
}
