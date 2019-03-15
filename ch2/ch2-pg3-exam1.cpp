#include <stdio.h>
#include <math.h>

int main() {
    int sqt = 1;
    int num = 1;
    while((num = pow(sqt++, 2)) <= 9999) {
        int highNum = num / 100;
        int lowNum = num % 100;
        if ((highNum / 10 == highNum % 10) && (lowNum / 10 == lowNum % 10)) {
            printf("%d", num);
        }
    }
    return 0;
}
