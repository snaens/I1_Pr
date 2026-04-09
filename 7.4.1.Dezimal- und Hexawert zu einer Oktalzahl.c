/* Erstellen Sie ein C-Programm okdezhex.c, das eine Oktalzahl einliest und dann die dieser
 * Oktalzahl entsprechende Dezimal- und Hexadezimalzahl ausgibt. Zur Erkennung einer falschen
 * Eingabe ist der Rückgabewert von scanf() nach dem Einlesen auszugeben.
 *
 *        Gib eine Oktalzahl ein: 7654321 ↩
 *        ---> 7654321(8) = 2054353(10) = 1f58d1(16)
 */

#include<stdio.h>

int main() {
    int zahl_eingabe;
    printf("Gib eine Oktalzahl ein: ");
    int ret = scanf("%o", &zahl_eingabe);
    if (!ret) {
        printf("Eingabe ist keine Oktalzahl!");
        return 1;
    }
    printf("---> %o(8) = %d(10) = %x(16)\n", zahl_eingabe, zahl_eingabe, zahl_eingabe);
}