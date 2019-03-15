#include <stdio.h>
#define SIZE 1000

int data[SIZE + 1];

int main() {
    printf("Box!\n");

    int n;
    bool hit = true;
    int loopCounter = 0;

    int j = 0;
    for (j = 0; j < 12; ++j) {
        scanf("%d", &n);
        data[n]++;
    }
    for (int i = 1; j > 0; ++i) {
        loopCounter++;
        if (data[i] == 12) {
            break;
        }
        if (data[i] == 8) {
            j -= 8;
            continue;
        }
        if (data[i] == 4) {
            j -= 4;
            continue;
        }
        if (data[i] == 0) {
            continue;
        }
        hit = false;
        break;
    }

    if (hit) {
        printf("These can form a box! (Through %d loops)\n", loopCounter);
    } else {
        printf("These cannot form a box! (Through %d loops)\n", loopCounter);
    }

    return 0;
}
