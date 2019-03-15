#include <stdio.h>
#include <math.h>

int main() {
    int counter = 0;
    for (int num = 100; num <= 999; num++ ) {
        int left = num / 100;
        int middle = (num / 10) % 10;
        int right = num % 10;
        if (pow(left, 3) + pow(middle, 3) + pow(right, 3) == num) {
            printf("The number %d daffodil is : %d\n", ++counter, num);
        }
    }
    return 0;
}
