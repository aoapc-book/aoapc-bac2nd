#include <stdio.h>

int main() {
    printf("Score, ACM/ICPC Seoul 2005, UVa1585 \n");
    int score = 0;
    int credit = 0;
    char c;

    while ((c = getchar()) != EOF) {
        if (c == 'X') {
            credit = 0;
            continue;
        }
        if (c == 'O') {
            credit++;
            score += credit;
            continue;
        }
        if (c == '\n') {
            printf("%d\n", score);
            score = 0;
        }
    }
    return 0;
}
