#include <stdio.h>

int main ()
{
    int a, b;
    scanf("%d\t%d", &a, &b);

    b = a + b;
    a = b - a;
    b = b - a;

    printf("%d\t%d", a, b);
    return 0;
}
