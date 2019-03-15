#include <stdio.h>
#include <string.h>
#define MAX_LIGHT 1010

int light[MAX_LIGHT];

int main() {
    printf("Opening lights\n");

    int k;
    int n;
    scanf("%d%d", &k, &n);
    memset(light, 0, sizeof(light));

    for (int i = 1; i <= k; i++) {
        for(int j = i; j <= n; j += i) {
            light[j] = !light[j];
        }
    }
    for (int k = 1; k <= n; k++) {
        if (light[k]) {
            printf("%d\t", k);
        }
    }
    return 0;
}
