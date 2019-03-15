#include <stdio.h>

int main() {
    printf("DNA Consensus String, ACM/ICPC Seoul 2006, UVa1368\n");
    int m = 0;
    int n = 0;
#ifdef LOCAL
    freopen("data/ch3-pg20-exer7.in", "r", stdin);
#endif
    scanf("%d%d", &m, &n);
    char s[m][n + 1];
    for (int i = 0; i < m; i++) {
        scanf("%s", s[i]);
    }
    char result[n + 1];

    for (int i = 0; i < n; i++) {
        int counter[20] = {0};
        for (int j = 0; j < m; j++) {
            counter[s[j][i] - 'A']++;
        }
        int max = 0;
        int maxIndex = 0;
        for (int k = 0; k < 20; k++) {
            if (counter[k] > max) {
                max = counter[k];
                maxIndex = k;
            }
        }
        result[i] = 'A' + maxIndex;
    }
    result[n] = '\0';
    printf("%s\n", result);
    return 0;
}
