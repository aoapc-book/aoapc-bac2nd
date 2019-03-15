#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 200

char s[MAX_SIZE];

int main() {
    printf("UVa401 Palindromes\n");

    const char raw[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
    const char mir[] = "1SE----8-0-W3-TYUIO-A2---HL-J-X-V--M";
    const char *message[] = {
                                " -- is nether symmetry nor palindrome!\n",
                                " -- is symmetry!\n",
                                " -- is palindrome!\n",
                                " -- is both symmetry and palindrome!\n"
                            };
    char *startP = s;
    char *endP = s;

    char c;
    memset(s, 0, sizeof(s));
    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            *endP++ = c;
        } else {
            endP--;
            int isSymmetry = 1;
            int isPalindrome = 1;
            while (startP <= endP && (isSymmetry || isPalindrome)) {
                if (isSymmetry && *startP != *endP) {
                    isSymmetry = 0;
                }
                if (isPalindrome) {
                    if (*startP != mir[strchr(raw, *endP) - raw]) {
                        isPalindrome = 0;
                    }
                }
                startP++;
                endP--;
            }
            strcat(s, message[isPalindrome * 2 + isSymmetry]);
            startP = endP = s + strlen(s);
        }
    }
    printf("%s", s);
    return 0;
}
