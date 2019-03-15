#include <stdio.h>

int main() {
    printf("Molar Mass, ACM/ICPC Seoul 2007, UVa1586\n");
    float atomMasses[4] = {12.01, 1.008, 16.00, 14.01};
    int credit = 0;
    float atomMass = 0;
    float molarMass = 0;
    char c;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            credit = credit ? credit * 10 + c - '0' : c - '0';
        } else if (c != '\n') {
            if (atomMass != 0) {
                molarMass += atomMass * (credit ? credit : 1);
                credit = 0;
            }
            if (c == 'C') {
                atomMass = atomMasses[0];
            } else if (c == 'H') {
                atomMass = atomMasses[1];
            } else if (c == 'O') {
                atomMass = atomMasses[2];
            } else if (c == 'N') {
                atomMass = atomMasses[3];
            }
        } else {
            molarMass += atomMass * (credit ? credit : 1);
            printf("%.3f g/mol\n", molarMass);
            molarMass = 0;
            atomMass = 0;
            credit = 0;
        }
    }

    return 0;
}
