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

#include <math.h>
#include <stdio.h>

int main() {
    int wert = 0;

    // 1
    short x = 7;
    wert = x & 1;
    printf("1.Wert: %d\n", wert);

    // 2
    unsigned short u = 256;
    // cast zu bool funktioniert nicht
    // das hier rechnet quasi `> 0`
    wert = u >> 8 ? true : false;
    printf("2.Wert: %b\n", wert);

    // 3
    // 0000 0010 0000 0000
    u = 520;
    const int num_bits = sizeof(unsigned short) * 8;
    wert = u >> (num_bits - 7) & 1; // bits um 16 - 7 shiften, 7. Bit von links ist jetzt erstes Bit rechts
    printf("3.Wert: %d\n", wert);

    // 4
    x = 1025;
    wert = x & ~127 // alle Bits unterhalb 128 verwerfen
                    ? true : false; // bitmask zu boolean umwandeln
    printf("4.Wert: %d\n", wert);

    // 5
    u = 43;
    //   = u % 4
    wert = u & 3 ? false : true; // bitmask zu boolean invertiert umwandeln
    printf("5.Wert: %d\n", wert);

    return 0;
}
