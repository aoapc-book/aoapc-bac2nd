#include <stdio.h>
#include <string.h>

int main() {
    printf("UVa272 Tex Quotes\n");

    int c;
    char s[100];
    char *p = s;
    bool inQuote = false;
    memset(s, 0, sizeof(s));
    while ((c = getchar()) != EOF) {
        if (c == '\"') {
            if (!inQuote) {
                *p++ = '`';
                *p++ = '`';
                inQuote = true;
            } else {
                *p++ = '\'';
                *p++ = '\'';
                inQuote = false;
            }
        } else {
            *p++ = c;
        }
    }
    printf("%s", s);
    return 0;
}
