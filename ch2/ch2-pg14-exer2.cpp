#include <stdio.h>

int main() {
    bool isAnswerable;
    int members;
    int mod3;
    int mod5;
    int mod7;

    while(scanf("%d %d %d", &mod3, &mod5, &mod7) == 3) {
        for(members = mod7 + 7; members <= 100; members += 7) {
            if (members % 5 != mod5) {
                continue;
            }
            if (members % 3 == mod3) {
                isAnswerable = true;
                break;
            }
        }
        if (!isAnswerable) {
            printf("No Answer!\n");
        } else {
            printf("%d\n", members);
            isAnswerable = false;
        }
    }
    return 0;
}
