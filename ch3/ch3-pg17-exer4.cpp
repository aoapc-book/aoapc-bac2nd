#include<stdio.h>
#include<string.h>

#define MAX_LENGTH 100

int main() {
    printf("Periodic Strings, UVa455\n");
    char s[MAX_LENGTH] = {0};

    scanf("%s", s);
    int n = strlen(s);
    int periodic = n;

    for (int i = 1; i < n; ++i) {
        int j;
        for (j = 0; j < n; ++j) {
            if (s[0 + j] != s[(i + j) % n]) {
                break;
            }
        }
        if (i > n / 2) {
            break;
        }
        if (j == n) {
            periodic = i;
            break;
        }
    }
    printf("%d\n", periodic);
    return 0;
}
