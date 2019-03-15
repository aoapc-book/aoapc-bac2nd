#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char s[MAX_SIZE];
char t[MAX_SIZE];

int main() {
    printf("All in All\n");
    scanf("%s%s", t, s);

    bool hit = false;
    unsigned i = 0;
    unsigned j = 0;
    while ( i < strlen(t) && j < strlen(s)) {
        if (t[i] == s[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }
    if (j == strlen(s)) {
        hit = true;
    }
    if (hit) {
        printf("%s can go to %s!\n", t, s);
    } else {
        printf("%s can not go to %s!\n", t, s);
    }
    return 0;
}
