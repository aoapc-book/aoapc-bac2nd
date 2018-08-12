#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if (a >= c) {
        a = a + c;
        c = a - c;
        a = a - c;
    }
    if (a >= b) {
        a = a + b;
        b = a - b;
        a = b - a;
    }
    if (b >= c) {
        b = b + c;
        c = b - c;
        b = b - c;
    }
        
    if (a + b > c) {
        if (a * a + b * b == c * c) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    } else {
      printf("not a triangle\n");
    }
    return 0;
}
