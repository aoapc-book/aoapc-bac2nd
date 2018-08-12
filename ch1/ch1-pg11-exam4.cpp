#include<stdio.h>

int main() {

    int numOfHeads,numOfLegs;
    int numOfChickens, numOfRabbits;

    scanf("%d\t%d", &numOfHeads, &numOfLegs);

    if (numOfHeads <= 0 || numOfLegs <= 0 || numOfLegs % 2 == 1) {
        printf("No answer\n");
        return 0;
    }
 
    numOfChickens = (numOfHeads * 4 - numOfLegs) / 2;
    numOfRabbits = numOfHeads - numOfChickens;

    if (numOfChickens < 0 || numOfRabbits < 0) {
        printf("No answer\n");
    } else {
        printf("%d  %d", numOfChickens, numOfRabbits);
    }

    return 0;
}
