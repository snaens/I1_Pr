/*
 * In einer unsigned short-Variable x sei der Wert 0x12ab gespeichert. Mit einer Zuweisung an x
 * sollen nun die beiden Bytes dieser Variable x vertauscht werden. Nach dieser Zuweisung sollte
 * in x der Wert 0xab12 stehen.
 * Erstellen Sie nun ein Programm, das den ursprünglichen und den neuen Wert als Hex-Zahl
 * ausgibt. Das Programm muss auch für jeden anderen zugewiesenen Wert den neuen Wert mit
 * den vertauschten Bytes ausgeben.

 * Hinweis: Schieben Sie die einzelnen Bytes jeweils an die neue Position und setzen Sie dann die
 * beiden geschobenen Bytes mit dem binären Oder-Operator wieder zu einem neuen 2-Byte Wert
 * zusammen.
 *   x = ............................................................................;
 */

#include <stdio.h>

int main() {
    unsigned short x = 0x12ab;
    printf("0x%X\n", x);

    x = (x & 0x00FF) << 8 | // unteres Byte extrahieren und nach oben schieben
        x >> 8; // oberes Byte nach unten schieben

    printf("0x%X\n", x);
}
