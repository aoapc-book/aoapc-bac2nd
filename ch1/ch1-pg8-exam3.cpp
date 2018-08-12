#include<stdio.h>

int main ()
{
    int a, b, temp;
    scanf("%d\t%d", &a, &b);

    temp = a;
    a = b;
    b = temp;

    printf("%d\t%d\n", a, b);
    return 0;
}
