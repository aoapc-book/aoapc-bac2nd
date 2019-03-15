#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 20

char s[MAX + 1];

int main() {
    printf("Floating-Point Numbers!\n");
#ifdef LOCAL
    freopen("data/ch3-pg25-exer12.in", "r", stdin);
#endif
    while (scanf("%s", s) == 1 && strcmp("0e0", s) != 0) {
        s[17] = '\0';
        printf("%s\n", s + 2);
        for (int E = 4; E <= 30; ++E) {
            double val = 0;
            char result[MAX + 1] = {0};
            for (int M = 0; M <=9; ++M) {
                for (int i = 0; i <= M; ++i) {
                    val += pow(2, i);
                }
                val *= pow(2, pow(2, E) - M);
                sprintf(result, "%lf", val);
                printf("%lf\n", val);
                if (strstr(result, s + 2)) {
                    printf("%s\n", result);
                    printf("M: %d\tE: %d", M, E);
                    return 0;
                }
            }
        }
    }
    return 0;
}
