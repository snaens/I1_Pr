/* Erstellen Sie ein C-Programm menue.c, das eine Menü-Auswahl einliest, und dem Benutzer un-
 * ter Verwendung von switch dann seine getroffene Wahl ausgibt.
 * Mögliche Abläufe des Programms menue.c:
 *    Hauptmenue
 *    ==========
 *    (A)endern
 *    (B)eenden
 *    (D)rucken
 *    (E)ingeben
 *    (L)oeschen
 *    Was wuenschen Sie zu tun ? d ↩
 *    ....... Sie haben (D)rucken gewaehlt .......
 *    Hauptmenue
 *    ==========
 *    (A)endern
 *    (B)eenden
 *    (D)rucken
 *    (E)ingeben
 *    (L)oeschen
 *    Was wuenschen Sie zu tun ? x ↩
 *    ....... Ihre Wahl ’X’ ist unerlaubt .......
 */

#include <ctype.h>
#include <stdio.h>

int main() {
    printf("Hauptmenue\n"
           "==========\n"
           "(A)endern \n"
           "(B)eenden \n"
           "(D)rucken \n"
           "(E)ingeben\n"
           "(L)oeschen\n"
           "Was wuenschen Sie zu tun ? ");
    unsigned char eingabe;
    scanf("%c", &eingabe);
    eingabe = toupper(eingabe);

    switch (eingabe) {
        case 'A':
        case 'a':
            printf("....... Sie haben (A)endern gewaehlt .......\n");
            break;
        case 'B':
            printf("....... Sie haben (B)eenden gewaehlt .......\n");
            break;
        case 'D':
            printf("....... Sie haben (D)rucken gewaehlt .......\n");
            break;
        case 'E':
            printf("....... Sie haben (E)ingeben gewaehlt .......\n");
            break;
        case 'L':
            printf("....... Sie haben (L)oeschen gewaehlt .......\n");
            break;
        default:
            printf("....... Ihre Wahl ’%c’ ist unerlaubt .......\n", eingabe);
    }
}
