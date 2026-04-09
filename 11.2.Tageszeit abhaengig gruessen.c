/* Erstellen Sie ein C-Programm gruss.c, welches eine Stunde einliest,
 * und abhängig von der Stunde folgendes ausgibt:
 *     Stunde          Ausgabe
 *    -----------------------
 *     23,0,1,2,3,4,5  Gute Nacht
 *     6,7,8,9,10      Guten Morgen
 *     11,12,13        Mahlzeit
 *     14,15,16,17     Schönen Nachmittag
 *     18,19,20,21,22  Guten Abend
 *     sonst           keine erlaubte Stunden-Angabe
 *
 *    Gib die Stunde der momentanen Uhrzeit ein: 1 ↩
 *    ---> Gute Nacht
 *
 *    Gib die Stunde der momentanen Uhrzeit ein: 9 ↩
 *    ---> Guten Morgen
 *
 *    Gib die Stunde der momentanen Uhrzeit ein: 12 ↩
 *    ---> Mahlzeit
 *
 *    Gib die Stunde der momentanen Uhrzeit ein: 16 ↩
 *    ---> Schönen Nachmittag
 *
 *    Gib die Stunde der momentanen Uhrzeit ein: 21 ↩
 *    ---> Guten Abend
 *
 *    Gib die Stunde der momentanen Uhrzeit ein: 24 ↩
 *    ---> 24 ist keine erlaubte Stunden-Angabe
 */

#include <stdio.h>

int main() {
    printf("Gib die Stunde der momentanen Uhrzeit ein: ");
    int uz = -1;
    scanf("%d", &uz);

    if (uz == 23 || uz == 0 || uz == 1 || uz == 2 || uz == 3 || uz == 4 || uz == 5)
        printf("Gute Nacht");
    else if (uz == 6 || uz == 7 || uz == 8 || uz == 9 || uz == 10)
        printf("Guten Morgen");
    else if (uz == 11 || uz == 12 || uz == 13)
        printf("Mahlzeit");
    else if (uz == 14 || uz == 15 || uz == 16 || uz == 17)
        printf("Schönen Nachmittag");
    else if (uz == 18 || uz == 19 || uz == 20 || uz == 21 || uz == 22)
        printf("Guten Abend");
    else
        printf("%d ist keine erlaubte Stunden-Angabe", uz);
}
