#include <stdio.h>

int main() {
    int num;
    int sum = 0;
    int min = (unsigned int)(~0) >> 1;
    int max = min + 1;
    int counter = 0;

    FILE *fin = fopen("data/ch2-pg11-exam5.in", "rb");
    FILE *fout = fopen("data/ch2-pg11-exam5.out", "wb");

    while(fscanf(fin, "%d", &num) == 1) {
        sum += num;
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
        counter++;
    }
    fprintf(fout, "%d, %d, %.2lf", min, max, (double)sum / counter);
    return 0;
}
