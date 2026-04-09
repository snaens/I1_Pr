/* Erstellen Sie ein C-Programm quersum.c, das eine 5-stellige Zahl Zeichen für Zeichen einliest,
 * also nicht als numerischen Wert, und dann die Quersumme zu dieser Zahl ausgibt.
 *
 * Ein Beispiel für einen möglichen Ablauf dieses Programms könnte sein:
 *    Gib 5-stellige Zahl ein: 98934 ↩
 *    Die Quersumme dieser Zahl ist 33
 */

#define NUM_LENGTH 5

#include <stdio.h>

int main() { printf("Gib 5-stellige Zahl ein: ");
    char in_string[NUM_LENGTH];
    scanf("%s", in_string); // GANZ BÖSE

    int quersumme = 0;
    for (int i = 0; i < NUM_LENGTH; i++)
        quersumme += in_string[i] - '0'; // use char code - offset starting from '0'

    printf("Die Quersumme dieser Zahl ist %d", quersumme);

    return 0;
}