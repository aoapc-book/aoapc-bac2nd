#include <stdio.h>
#define MAX_SIZE 1000000000

int a[MAX_SIZE];

int main() {
    printf("Reversing Input\n");
    int n = 0;

    while(scanf("%d", &a[n]) == 1) {
        n++;
    }

    for (int i = n - 1; i >= 1; --i) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[0]);
 
    return 0;
}
