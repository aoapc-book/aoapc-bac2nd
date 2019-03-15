#include <stdio.h>
#include <string.h>

#define MAX 55 + 5

char s[MAX];

int main() {
    printf("UVa1584 Circular Sequence Another Way.\n");
    int minP = 0;
    int n = 0;
    while (scanf("%s", s) == 1) {
        n = strlen(s);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[(i + j) % n] == s[(minP + j) % n]) {
                    continue;
                }
                if (s[(i + j) % n] < s[(minP + j) % n]) {
                    minP = i;
                }
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            putchar(s[(minP + i) % n]);
        }
        putchar('\n');
    }
    return 0;
}
