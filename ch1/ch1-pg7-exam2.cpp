#include <stdio.h>

int main()
{
    int num;
    int firstD, secondD, thirdD;
    scanf("%d", &num);

    firstD = num / 100;
    secondD = num % 100 / 10;
    thirdD = num % 10;

    printf("%03d\n", thirdD * 100 + secondD * 10 + firstD);

    return 0;
}
