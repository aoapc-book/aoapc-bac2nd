#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 1000

int main() {
    printf("UVa340 Master-Mind Hints\n");
    int counterA = 0;
    int counterB = 0;
    int answerLen = 0;
    int staticsCounter = 0;
    char *inputStr;
    char *commitStr;
    char *realAnswerStr;
    char *workAnswerStr;
    char staticsAnswer[MAX_ARRAY_SIZE];
    char buffAnswer[MAX_ARRAY_SIZE];

#ifdef LOCAL
    freopen("data/ch3-pg8-exam4.in", "r", stdin);
#endif

    inputStr = (char*)malloc(sizeof(char) * 4);
    while (scanf("%s", inputStr) == 1) {
        int inputDigit = atoi(inputStr);
        if (answerLen == 0 && inputDigit == 0) {
            break;
        }
        if (answerLen == 0) {
            answerLen = inputDigit;
            inputStr = (char*)malloc(sizeof(char) * answerLen);
            commitStr = (char*)malloc(sizeof(char) * answerLen);
            realAnswerStr = (char*)malloc(sizeof(char) * answerLen);
            workAnswerStr = (char*)malloc(sizeof(char) * answerLen);
            memset(commitStr, '0', answerLen);
            memset(realAnswerStr, 0, answerLen);
            memset(workAnswerStr, 0, answerLen);
            continue;
        }
        if (strcmp(inputStr, commitStr) == 0) {
            memset(realAnswerStr, 0, answerLen);
            answerLen = 0;
            continue;
        }
        if (strlen(realAnswerStr) == 0) {
            strcpy(realAnswerStr, inputStr);
            sprintf(buffAnswer, "The [%d] statics set is:\n", ++staticsCounter);
            strcat(staticsAnswer, buffAnswer);
            continue;
        }
        strcpy(workAnswerStr, realAnswerStr);
        for (int i = 0; i < answerLen; i++) {
            for (int j = 0; j < answerLen; j++) {
                if (inputStr[i] != workAnswerStr[j]) {
                    continue;
                }
                if (i == j) {
                    counterA++;
                    workAnswerStr[j] = 'x';
                    break;
                }
                if (inputStr[i] != workAnswerStr[i] && inputStr[j] != workAnswerStr[j]) {
                    counterB++;
                    workAnswerStr[j] = 'x';
                    break;
                }

            }
        }
        sprintf(buffAnswer, "\t<%d, %d>\n", counterA, counterB);
        strcat(staticsAnswer, buffAnswer);
        counterA = 0;
        counterB = 0;
    }
    printf("%s", staticsAnswer);
    return 0;
}
