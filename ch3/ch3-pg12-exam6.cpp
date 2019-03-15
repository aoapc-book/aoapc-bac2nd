#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000

char s[MAX_SIZE];

int main() {
    printf("UVa1584 Circular Sequence\n");

    int n = 0;
    while(scanf("%s", s) == 1) {
        n = (int)strlen(s);
        bool status[n];
        for (int i = 0; i < n; ++i) {
            status[i] = true;
        }
        int outC = n;
        int curMinP = 0;
        for (int r = 0; r < n; ++r) {
            if (outC == 1) {
                break;
            }
            for (int i = 0; i < n; ++i) {
                if (!status[i]) {
                    continue;
                }
                if (s[(i + r) % n] < s[(curMinP + r) % n]) {
                    curMinP = i;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (!status[i]) {
                    continue;
                }
                if (s[(i + r) % n] != s[(curMinP + r) % n]) {
                    status[i] = false;
                    outC--;
                }
            }
        }
        for (int i = curMinP; i < n + curMinP; ++i) {
            printf("%c", s[i % n]);
        }
        printf("\n");
    }
    return 0;
}
