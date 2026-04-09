/* Erstellen Sie ein C-Programm sumunger.c, das bei 1 beginnend eine Summe von ungeraden Zah-
 * len berechnet. Bis zu welchem Endewert dabei die ungeraden Zahlen aufzuaddieren sind, ist
 * einzugeben. Mögliche Abläufe dieses Programms sumunger.c:
 *     Bis zu welchem n sollen alle ungeraden Zahlen aufaddiert werden: 5 ↩
 *     Summe der ungeraden Zahlen bis 5: 9
 *
 *     Bis zu welchem n sollen alle ungeraden Zahlen aufaddiert werden: 100 ↩
 *     Summe der ungeraden Zahlen bis 100: 2500
 *
 *     Bis zu welchem n sollen alle ungeraden Zahlen aufaddiert werden: 3600 ↩
 *     Summe der ungeraden Zahlen bis 3600: 3240000
 */

#include <stdio.h>

int main() {
    printf("Bis zu welchem n sollen alle ungeraden Zahlen aufaddiert werden: ");
    int n;
    scanf("%d", &n);

    int ausgabe = 0;
    for (int i = 1; i <= n; i += 2)
        ausgabe += i;
    printf("Summe der ungeraden Zahlen bis %d: %d", n, ausgabe);
}
