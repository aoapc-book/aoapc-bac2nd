#include <stdio.h>
#define MAX_SIZE 1000

int snake[MAX_SIZE][MAX_SIZE];

int main() {
    printf("Snake Metrics\n");

    int n;
    scanf("%d", &n);

    int x = 0;
    int y = n - 1;
    int direction = 1;
    for (int counter = 1; counter <= n * n; counter++) {
        snake[x][y] = counter;
        if (direction % 4 == 1) {
            if (x < n - 1 && !snake[x + 1][y]) {
                x++;
            } else {
                direction++;
            }
        }
        if (direction % 4 == 2) {
            if (y > 0 && !snake[x][y - 1]) {
                y--;
            } else {
                direction++;
            }
        }
        if (direction % 4 == 3) {
            if (x > 0 && !snake[x - 1][y]) {
                x--;
            } else {
                direction++;
            }
        }
        if (direction % 4 == 0) {
            if (y < n - 1 && !snake[x][y + 1]) {
                y++;
            } else {
                direction++;
                x++;
            }
        }
    }

    for (int x = 0; x < n; x++ ) {
        for (int y = 0; y < n; y++ ) {
            printf("%d\t", snake[x][y]);
        }
        printf("\n");
    }
    return 0;
}
