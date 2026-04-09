/* Erstellen Sie ein C-Programm ljahrkm.c, dass bei der Eingabe von Lichtjahren die diesen Licht-
 * jahren entsprechenden Kilometer ausgibt; 1 Lichtjahr = 9,4605 Billionen km.
 * Mögliche Programmabläufe:
 *    Wieviele Lichtjahre: 3.4 ↩
 *    -----> 32165700042752.000000 Kilometer
 *    Wieviele Lichtjahre: 1000000 ↩
 *    -----> 9460500411082342400.000000 Kilometer
 */
#include <stdio.h>

int main() {
    printf("Wieviele Lichtjahre: ");

    float lichtjahre = 0.f;
    scanf("%f", &lichtjahre);

    // Aus angabe geklaut
    const float ly_to_km = 9460500411082342400 / 1000000;

    lichtjahre *= ly_to_km;
    printf("-----> %.2f Kilometer\n", lichtjahre);

    return 0;
}
