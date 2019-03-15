#include <stdio.h>
#include <string.h>

#define MAX 100000

int generator[MAX + 1];

int main() {
    printf("UVa1583 Digit Generator\n");
    for (int i = 0; i <= MAX; ++i) {
        int sum = i;
        char strBuff[6];
        sprintf(strBuff, "%d", i);
        for (int j = 0; j < strlen(strBuff); ++j) {
            sum += strBuff[j] - '0';
        }
        if (generator[sum] == 0) {
            generator[sum] = i;
        }
    }
    int n;
    while(scanf("%d", &n) == 1) {
        if (n <= MAX) {
            printf("%d\n", generator[n]);
        } else {
            printf("Please input a number not larger than %d!\n", MAX);
        }
    }
    return 0;
}
