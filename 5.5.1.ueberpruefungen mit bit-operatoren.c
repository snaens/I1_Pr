/*
Erstellen Sie ein Programm, dass die Werte der Ausdrücke der unten angegebenen Überprüfun-
gen einer int-Variable wert zuweist und diese dann als Dezimalzahl, also mit
  printf("n.Wert: %d\n", wert);
ausgibt.
Bei den Überprüfungen sollten Sie nur logische Operatoren und Bit-Operatoren benutzen. So
könnte z.B. mit dem Ausdruck
  x & 0x8000
überprüft werden, ob der Wert einer short-Variablen negativ ist, da bei dieser Verknüpfung alle
Bits außer dem ersten auf 0 gesetzt werden. Ist das 1.Bit 1 (Negative Zahl), so ist der Wert dieser
Verknüpfung verschieden von 0, was in C als TRUE gewertet wird. Ist dagegen das 1.Bit 0
(positive Zahl), so ist der Wert dieser Verknüpfung 0, was in C als FALSE gewertet wird. Geben
Sie nun entsprechende Ausdrücke an, die überprüfen,

1. ob der Wert der short-Variablen x ungerade ist.
  (für x = 7)
2. ob der Wert der unsigned short-Variablen u groesser als 255 ist.
  (für u = 256)
3. ob das 7.Bit (von links her gezählt) in der unsigned short-Variablen u auf 1 gesetzt ist.
  (für u = 520)
4. ob der Wert der short-Variablen x im Intervall [0,127] liegt.
  (für x = 120)
5. ob der Wert der unsigned short-Variablen u durch 4 teilbar ist.
  (für u = 43)
*/

#include <stdio.h>

int main () {
    int wert = 0;

    // 1
    short x = 7;
    wert = x & 1;
    printf("1.Wert: %d\n", wert);

    // 2
    unsigned short u = 254;
    wert = u >> 8; // bits unter #9 ignorieren (< 256)
    for (int i = 0; i <= 7; i++) { wert |= u>>1; } // restlichen bits nach Trues absuchen
    printf("2.Wert: %b\n", wert);

    // 3
    u = 520;
    wert = u >> 6 & 1;
    printf("3.Wert: %d\n", wert);

    // 4
    x = 129;
    wert = /*!(*/x >> 7; //& 1);
    printf("4.Wert: %b\n", wert);

    return 0;
}