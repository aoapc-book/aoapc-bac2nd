#include<stdio.h>
#include<string.h>
#define MAX 1000

int main() {
    printf("Crossword Answers, ACM/ICPC World Finals 1994, UVa232\n\n");
    char s[MAX] = {0};
    char c = 0;
    int m = 0;
    int n = 0;
#ifdef LOCAL
    freopen("data/ch3-pg19-exer6.in", "r", stdin);
#endif
    char *p = s;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            m++;
            continue;
        }
        if (m == 0) {
            n++;
        }
        *p++ = c;
    }
    char (*array)[n] = (char(*)[n])s;
    printf("Across:\n-------------\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] == '*') {
                continue;
            }
            if (j == 0 || array[i][j - 1] == '*') {
                if (array[i][j + 1] != '*' && j + 1 < n) {
                    for (int k = j; array[i][k] != '*' && k < n; k++) {
                        printf("%c", array[i][k]);
                    }
                    printf("\n");
                }
            }
        }
    }
    printf("\nDown:\n-------------\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] == '*') {
                continue;
            }
            if (i == 0 || array[i - 1][j] == '*') {
                if (array[i + 1][j] != '*' && i + 1 < m) {
                    for (int k = i; array[k][j] != '*' && k < m; k++) {
                        printf("%c", array[k][j]);
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
