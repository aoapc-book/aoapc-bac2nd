#include <stdio.h>
#include <string.h>

char DIC[] = "1234567890-=!@#$%^&*()_+QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
//char *DIC = "1234567890-=!@#$%^&*()_+QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
    printf("UVa10082 WERTYU\n");

    char s[100];
    //char s[];
    memset(s, 0, sizeof(s));
    char *p = s;

    int c;
    char *addr;
    while((c = getchar()) != EOF) {
        if (addr = strchr(DIC, c)) {
            *p++ = DIC[addr - DIC - 1];
        } else {
            *p++ = c;
        }
    }

    printf("%s", s);
    return 0;
}
