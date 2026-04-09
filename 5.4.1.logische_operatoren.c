/* Erstellen Sie ein Programm, das die Werte folgender Ausdrücke einer int-Variable wert zuweist
 * und diese dann als Dezimalzahl, also mit:
 * 1. ob der Wert der Variablen a im Intervall [-20,100] liegt:
 *   (für a = -15)
 * 2. ob Wert der Variablen x negativ ist, aber zugleich auch
 *   der Wert der Variablen y im Intervall [5,30] liegt:
 *   (für x = 1 und y = 7)
 * 3. ob Wert der ganzzahligen Variablen z ungerade ist und
 *   zugleich auch durch 3 und 5 teilbar ist:
 *   (für z = 15)
 * 4. ob der Wert der ganzzahligen Variablen jahr
 *   - durch 400 oder
 *   - durch 4, aber nicht durch 100 teilbar ist (Bedingung für ein Schaltjahr):
 *   (für jahr = 2100)
 * 5. ob das Produkt der beiden int-Variablen a und b in den Datentyp unsigned char
 *   ohne Überlauf untergebracht werden kann:
 *   (für a = 25 und b = 10)
 * 6. ob der Wert der char-Variablen antwort
 *   weder das Zeichen ’j’ noch das Zeichen ’J’ enthält:
 *   (für antwort = ’A’)
 * 7. ob der Wert der int-Variablen zaehler nicht im Intervall [5,25] liegt:
 *   (für zaehler = 30)
 */

#include <math.h>
#include <stdio.h>

int main() {
    int wert = 0;
    // 1
    int a = -15;
    wert = a >= -20 && a <= 100;
    printf("1.Wert: %d\n", wert);

    // 2
    int x = 1;
    int y = 7;
    wert = x <= 0 && (y >= 5 && y <= 30);
    printf("2.Wert: %d\n", wert);

    // 3
    int z = 15;
    wert = z % 2 && z % 3 == 0 && z % 5 == 0;
    printf("3.Wert: %d\n", wert);

    // 4
    int jahr = 2100;
    wert = jahr % 400 == 0 || (jahr % 4 == 0 && jahr % 100 != 0);
    printf("4.Wert: %d\n", wert);

    // 5
    a = 25;
    int b = 10;
    if (a*b >= 0)
      wert = a * b < pow(2, 8 * sizeof(unsigned char));
    else wert = 0;
    printf("5.Wert: %d\n", wert);

    // 6
    char c = 'A';
    wert = c != 'j' && c != 'J';
    printf("6.Wert: %d\n", wert);

    // 7
    int zaehler = 30;
    wert = !(zaehler >= 5 && zaehler <= 25);
    printf("7.Wert: %d\n", wert);


    return 0;
}
