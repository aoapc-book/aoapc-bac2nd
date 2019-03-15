#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ARRAY_SIZE 10000

char outS[MAX_ARRAY_SIZE];
char outSBuff[100];

int main() {
    printf("UVa340 Master-Mind Hints Another Way\n");
    int n;
    int digit;
    int gameCounter = 0;

#ifdef LOCAL
    freopen("data/ch3-pg9-exam4.in", "r", stdin);
#endif

    while(scanf("%d", &n) == 1 && n) {
        int answer[n];
        int answerStatistics[10] = {0};
        int challengeStatistics[10] = {0};
        sprintf(outSBuff, "Game %d:\n", ++gameCounter);
        strcat(outS, outSBuff);

        int digitCounter = 0;
        int counterA = 0;
        int counterB = 0;
        while(scanf("%d", &digit) == 1) {
            if (digitCounter / n == 0) {
                answerStatistics[digit]++;
                answer[digitCounter] = digit;
                digitCounter++;
                continue;
            }
            challengeStatistics[digit]++;
            if (challengeStatistics[0] == n) {
                challengeStatistics[0] = 0;
                break;
            }
            if (digit == answer[digitCounter % n]) {
                counterA++;
            }
            if (digitCounter % n == n - 1) {
                for (int i = 1; i <= 9; i++) {
                    counterB += answerStatistics[i] < challengeStatistics[i] ? answerStatistics[i] : challengeStatistics[i];
                    challengeStatistics[i] = 0;
                }
                counterB -= counterA;
                sprintf(outSBuff, "\t(%d,%d)\n", counterA, counterB);
                strcat(outS, outSBuff);
                counterA = counterB = 0;
            }
            digitCounter++;
        }
    }
    printf("%s", outS);
    return 0;
}
