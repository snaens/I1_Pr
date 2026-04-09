/*
 * Erstellen Sie ein Programm, das die folgenden beiden mathematischen Ausdrücke berechnet
 * und jeweils das Ergebnis ausgibt. Klammern sollten dabei nur dann verwendet werden, wenn
 * diese unbedingt notwendig sind.
 */

#include <stdio.h>
int main() {
    double gleichung_1 = 18 / 2 * ((4 + 5) / (9 - 6)) % (6 + 8 / 4);
    double gleichung_2 = (4 - 10 + (double) (100 + 100 - 40 + 80) / (5 * 2 * 4) + 36) / ((double) (90 - 30) / (10 - 5));

    printf("%lf\n", gleichung_1);
    printf("%lf\n", gleichung_2);
}
