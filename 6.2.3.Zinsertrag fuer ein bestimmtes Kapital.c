/* Für ein Anfangskapital K 0 sind in Abhängigkeit vom Festlegungszeitraum T (Tage) und dem
 * Jahreszinsfuß (Z in %) die Zinsen und das Endkapital zu errechnen. Dazu benutzt man folgende
 * Formeln:
 *    Zinsen = (K₀ * Z * T) / (100 ∗ 360) [1]
 *    Endkapital = K0 + Zinsen
 * Erstellen Sie ein C-Programm zinskapi.c, das zunächst ein Anfangskapital, den dafür gewährten
 * Zinsfuß (in Prozent) und die Anlegedauer einliest, und dann die dafür zu zahlenden Zinsen
 * und das resultierende Endkapital ausgibt, wie z. B.:
 *    Anfangskapital: 120000 ↩
 *    Jahreszins (in %): 7.43 ↩
 *    Wieviele Tage soll Kapital angelegt werden: 430 ↩
 *
 *    Anfangskapital: 120000.00
 *    Zinsen (nach 430 Tage): 10649.67
 *    --------------------------------------------------------
 *    Endkapital:
 *    130649.66
 *
 *
 *    Anfangskapital: 13500 ↩
 *    Jahreszins (in %): 5.7 ↩
 *    Wieviele Tage soll Kapital angelegt werden: 200 ↩
 *
 *    Anfangskapital: 13500.00
 *    Zinsen (nach 200 Tage): 427.50
 *    --------------------------------------------------------
 *    Endkapital:
 *    13927.50
 *
 *    [1] Bei der Zinsberechnung werden immer 360 Tage für ein Jahr angenommen
 */

#include <stdio.h>
int main () {
    printf("Anfangskapital: ");
    double anfangskapital;
    scanf( "%lf", &anfangskapital);

    printf("Jahreszins (in %): ");
    double jahreszins;
    scanf( "%lf", &jahreszins);

    printf("Wieviele Tage soll Kapital angelegt werden: ");
    int zeitdauer_tage;
    scanf( "%d", &zeitdauer_tage);

    double zinsen = (anfangskapital * jahreszins * zeitdauer_tage) / (360 * 100);

    printf("\n");
    printf("Anfangskapital: %.2lf\n", anfangskapital);
    printf("Zinsen (nach %d Tagen): %.2lf\n", zeitdauer_tage, zinsen);
    printf("--------------------------------------------------------\n");
    printf("Endkapital:\n%.2lf\n", zinsen + anfangskapital);

}