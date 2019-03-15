#include <stdio.h>
#include <string.h>

#define MAX 100

char n1[MAX + 1];
char n2[MAX + 1];
char *pMin;
char *pMax;
int lMin;
int lMax;
int lDiff;

void prepare() {
    printf("Kickdown!\n");
#ifdef LOCAL
    freopen("data/ch3-pg24-exer11.in", "r", stdin);
#endif
    scanf("%s%s", n1, n2);

    int l1 = strlen(n1);
    int l2 = strlen(n2);

    if (l1 >= l2) {
        pMax = n1;
        pMin = n2;
        lMax = l1;
        lMin = l2;
        lDiff = l1 - l2;
    } else {
        pMax = n2;
        pMin = n1;
        lMax = l2;
        lMin = l1;
        lDiff = l2 - l1;
    }
}

int main() {
    prepare();

    int result = lMax;
    bool hit = false;
    for (int i = 0; i <= lDiff; ++i) {
        int j;
        for (j = 0; j < lMin; ++j) {
            if (*(pMin + j) + *(pMax + i + j) - 2 * '0' > 3) {
                break;
            }
        }
        if (j == lMin) {
            hit = true;
            break;
        }
        for (j = 0; j < lMin; ++j) {
            if (*(pMin + lMin - 1 - j) + *(pMax + i + j) - 2 * '0' > 3) {
                break;
            }
        }
        if (j == lMin) {
            hit = true;
            break;
        }
    }
    if (!hit) {
        for (int i = 1; i <= lMin; ++i) {
            int j;
            for (j = 0; j < lMin - i; ++j) {
                if (*(pMin + i + j) + *(pMax + j) - 2 * '0' > 3) {
                    break;
                }
            }
            if (j == lMin - i) {
                hit = true;
                result = lMax + i;
                break;
            }
            for (j = 0; j < lMin - i; ++j) {
                if (*(pMin + lMin - 1 - i - j) + *(pMax + j) - 2 * '0' > 3) {
                    break;
                }
            }
            if (j == lMin - i) {
                hit = true;
                result = lMax + i;
                break;
            }
            for (j = 0; j < lMin - i; ++j) {
                if (*(pMin + i + j) + *(pMax + lMax - 1 - j) - 2 * '0' > 3) {
                    break;
                }
            }
            if (j == lMin - i) {
                hit = true;
                result = lMax + i;
                break;
            }
            for (j = 0; j < lMin - i; ++j) {
                if (*(pMin + lMin - 1 - i - j) + *(pMax + lMax - 1 - j) - 2 * '0' > 3) {
                    break;
                }
            }
            if (j == lMin - i) {
                hit = true;
                result = lMax + i;
                break;
            }
        }
    }

    printf("%d\n%d\n", lMin, lMax);
    printf("The min length of container is: %d\n", result);
    return 0;
}
