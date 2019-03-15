#include<stdio.h>

int main() {
    printf("Puzzle, ACM/ICPC World Finals 1993, UVa227\n");

#ifdef LOCAL
    freopen("data/ch3-pg18-exer5.in", "r", stdin);
#endif

    char puzzle[5][5] = {0};
    char *p = puzzle[0];
    char move = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < 25; ++i) {
        scanf("%s", p++);
        if (*(p - 1) == '-') {
            x = i / 5;
            y = i % 5;
        }
    }
    while ((move = getchar()) != EOF && move != 0) {
        switch(move) {
            case 'A':
                puzzle[x][y] = puzzle[(x + 5 - 1) % 5][y];
                x = (x + 5 - 1) % 5;
                puzzle[x][y] = '-';
                break;
            case 'B':
                puzzle[x][y] = puzzle[(x + 1) % 5][y];
                x = (x + 1) % 5;
                puzzle[x][y] = '-';
                break;
            case 'L':
                puzzle[x][y] = puzzle[x][(y + 5 - 1) % 5];
                y = (y + 5 - 1) % 5;
                puzzle[x][y] = '-';
                break;
            case 'R':
                puzzle[x][y] = puzzle[x][(y + 1) % 5];
                y = (y + 1) % 5;
                puzzle[x][y] = '-';
                break;
            default:
                ;
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%c ", puzzle[i][j]);
        }
        printf("\n");
    }
    return 0;
}
