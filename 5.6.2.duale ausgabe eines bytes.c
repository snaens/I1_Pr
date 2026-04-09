/* Schreiben Sie ein C-Programm, dass Ihnen das Bitmuster des Wertes in der char-
 * Variablen zeichen ausgibt. Es bleibt dabei Ihnen überlassen, welche char-Konstante Sie zuvor
 * der Variablen zeichen zuweisen. Für z. B. zeichen = ’e’ sollte das Programm das zugehörige
 * Bitmuster (ASCII-Code)
 *    01100101
 * ausgeben. Das Programm muss auch für jede andere Zuweisung das korrekte Bitmuster ausge-
 * ben.
 * Hierzu noch ein Hinweis:
 * Geben Sie jedes einzelne Bit mit einem printf() aus. Sie müssen also printf() achtmal auf-
 * rufen, um jedes einzelne Bit von zeichen auszugeben.
 * Die Idee dieses Programms ist, das auszugebende Bit mit » an die letzte Stelle zu schieben
 * und dann eventuell zuvor stehende Einsen zu löschen. Das Löschen der vorderen 7 Bits wird
 * dadurch erreicht, dass das mit » entstandene Bitmuster und die Zahl 1 mit dem Operator &
 * verknüpft werden. Um z. B. das dritte Bit von vorne auszugeben, wird
 *    printf("%d", (zeichen » 5) & 1)
 * aufgerufen:
 *    zeichen:
 *    01100101 = £e£
 *    zeichen >> 5: 00000011 = 3
 *    00000001 = 1
 *    ------------------------------
 *    (zeichen >> 5) & 1: 00000001 = 1 (Ausgabe durch printf())
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    char eingabe;
    if (argc >= 2) {
        // programmargument: erster Buchstabe
        eingabe = *argv[1];
    } else
        eingabe = 's';

    printf("Werte von %c:\n", eingabe);

    printf("Dec: %d\n", eingabe);
    printf("Hex: 0x%X\n", eingabe);
    // printf("Bin: 0b%b\n", eingabe); // funktioniert auf linux:gcc 15.2.1
    printf("Bin: 0b");
    for (int i = (sizeof(eingabe) * 8) - 1; i >= 0; --i) {
        printf("%d", (eingabe >> i) & 1);
        if (i % 4 == 0) printf(" "); // alle 4 chars (~ hex zahl) ein leerzeichen
    }
    printf("\n");

    return 0;
}
