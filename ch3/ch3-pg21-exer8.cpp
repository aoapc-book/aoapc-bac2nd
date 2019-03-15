#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

char s[MAX_SIZE + 1];
char o[MAX_SIZE + 1];

int main() {
    printf("Repeating Decimals, ACM/ICPC World Finals 1990, UVa202\n");
    int a = 0;
    int b = 0;

    scanf("%d%d", &a, &b);
    sprintf(s, "%d.", a / b);
    sprintf(o, "%d.", a / b);

    int mod = a % b;
    for (int i = strlen(s); i < MAX_SIZE; ++i) {
       s[i] = '0' + mod * 10 / b;
       mod = mod * 10 % b;
    } 

    int sec = 0;
    int MAX_SEC = (MAX_SIZE - strlen(o)) / 2;
    int STRT_POS = strlen(o);
    for (int strtP = strlen(o); strtP < MAX_SIZE; ++strtP) {
        int oP = strtP;
        o[oP++] = '(';
        for (sec = 1; sec < MAX_SEC; ++sec) {
            o[oP++] = s[strtP + sec - 1];
            bool hit = true;
            for (int i = 0; i < sec && hit; ++i) {
                int curP = strtP;
                while (curP + i + sec < MAX_SIZE && hit) {
                    if (s[curP + i] != s[curP + i + sec]) {
                        hit = false;
                    }
                    curP += sec;
                }
            }
            if (hit && oP < STRT_POS + MAX_SEC) {
                o[oP++] = ')';
                o[oP] = '\0';
                printf("%s\n", s);
                printf("%s\n", o);
                printf("%d\n", sec);
                return 0;
            }
        }
        o[strtP] = s[strtP];
    }
    o[MAX_SIZE] = '\0';
    printf("%s\n", s);
    printf("%s\n", o);
    printf("The result is not Repeating Decimals\n");
    return 0;
}
