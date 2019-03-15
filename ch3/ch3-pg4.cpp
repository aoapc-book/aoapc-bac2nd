#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("Vertical Form Problem\n");
    //char *s = (char*)malloc(sizeof(char));
    char s[12];

    scanf("%s", s);

    int counter = 0;
    for (int abc = 111; abc <= 999; abc++) {
        for (int de = 11; de <= 99; de++) {
            char *vc = (char*)malloc(sizeof(char) * 30);
            sprintf(vc, "%d%d%d%d%d", abc, de, abc * (de % 10), abc * (de / 10), abc * de);

            bool isValid = true;
            while(*vc) {
                if (!strchr(s, *vc)) {
                    isValid = false;
                    break;
                }
                vc++;
            }
            if (isValid) {
                printf("\n<%d>\n", ++counter);
                printf("%5d\nX%4d\n-----\n%5d\n%4d \n-----\n%5d\n",
                        abc, de, abc * (de % 10), abc * (de / 10), abc * de);
            }
        }
    }
    if (!counter) {
        printf("There is no answer!");
    }
    return 0;
}
