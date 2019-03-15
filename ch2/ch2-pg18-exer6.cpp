#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int abc = 0;
    int def = 0;
    int ghi = 0;

    for (int a = 1; a <= 9; a++) {
        abc = a * 100;
        for (int b = 1; b <= 9; b++) {
            if (b == a) {
                continue;
            }
            abc = a * 100 + b * 10;
            for (int c = 1; c <= 9; c++) {
                if (c == a || c == b) {
                    continue;
                }
                abc = a * 100 + b * 10 + c;
                for (int d = 1; d <= 9; d++) {
                    if (d == a || d == b || d == c) {
                        continue;
                    }
                    def = d * 100;
                    for (int e = 1; e <= 9; e++) {
                        if (e == a || e == b || e == c || e == d) {
                            continue;
                        }
                        def = d * 100 + e * 10;
                        for (int f = 1; f <= 9; f++) {
                            if (f == a || f == b || f == c || f == d || f == e) {
                                continue;
                            }
                            def = d * 100 + e * 10 + f;
                            for (int g = 1; g <= 9; g++) {
                                if (g == a || g == b || g == c || g == d || g == e || g == f) {
                                    continue;
                                }
                                ghi = g * 100;
                                for (int h = 1; h <= 9; h++) {
                                    if (h == a || h == b || h == c || h == d || h == e || h == f || h == g) {
                                        continue;
                                    }
                                    ghi = g * 100 + h * 10;
                                    for (int i = 1; i <= 9; i++) {
                                        if (i == a || i == b || i == c || i == d || i == e || i == f || i == g || i == h) {
                                            continue;
                                        }
                                        ghi = g * 100 + h * 10 + i;
                                        double abcdef = 1.0 * abc / def;
                                        char *abcdefChars = (char*)malloc(sizeof(char));
                                        gcvt(abcdef, 5, abcdefChars);
                                        double defghi = 1.0 * def / ghi;
                                        char *defghiChars = (char*)malloc(sizeof(char));
                                        gcvt(defghi, 5, defghiChars);
                                        if (strcmp(abcdefChars, defghiChars) == 0) {
                                            printf("%d\t%d\t%d\n", abc, def, ghi);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
