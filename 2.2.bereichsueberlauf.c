/* Hier wird wieder angenommen, dass der Datentyp short zwei Bytes belegt. Geben Sie nun die
 * resultierende Dualdarstellung mit entsprechendem Dezimalwert für folgende Dezimalzahlen
 * im short-Datentyp an:
 */

#define NR1 (-65000)
#define NR2 100000
#define NR3 33000
#define NR4 65535

#include <stdio.h>

int main() {
    printf("### 1 ###\n"
           "in:  %d(10)\n"
           "bin: %b(2)\n"
           "dec: %d(10)\n",
           NR1, (short) NR1, (short) NR1);
    printf("\n### 2 ###\n"
           "in:  %d(10)\n"
           "bin: %b(2)\n"
           "dec: %d(10)\n",
           NR2, (short) NR2, (short) NR2);
    printf("\n### 3 ###\n"
           "in:  %d(10)\n"
           "bin: %b(2)\n"
           "dec: %d(10)\n",
           NR3, (short) NR3, (short) NR3);
    printf("\n### 4 ###\n"
           "in:  %d(10)\n"
           "bin: %b(2)\n"
           "dec: %d(10)\n",
           NR4, (short) NR4, (short) NR4);
}
