/* Erstellen Sie ein C-Programm benzinv.c, dass die durchschnittliche Geschwindigkeit und den
 * durchschnittlichen Benzinverbrauch für eine Autofahrt berechnet. Die gefahrene Zeit (Stunden
 * und Minuten), die gefahrenen Kilometer und die gebrauchten Liter sind dazu einzugeben, wie
 * z. B.:
 *    Gefahrene Stunden: 2 ↩
 *    Gefahrene Minuten: 7 ↩
 *    Gefahrene Kilometer: 234 ↩
 *    Gebrauchte Liter: 18.9 ↩
 *      Durchschnittl. Geschwindigkeit: 110.55 km/h (30.71 m/s)
 *      Durchschnittl. Benzinverbrauch: 8.08 l/100 km

 *    Gefahrene Stunden: 9 ↩
 *    Gefahrene Minuten: 43 ↩
 *    Gefahrene Kilometer: 782 ↩
 *    Gebrauchte Liter: 65.7 ↩
 *      Durchschnittl. Geschwindigkeit: 80.48 km/h (22.36 m/s)
 *      Durchschnittl. Benzinverbrauch: 8.40 l/100 km
 */

#include <stdio.h>

int main() {
    double fahrzeit_h = 0;
    printf("Gefahrene Stunden: ");
    scanf("%lf", &fahrzeit_h);

    double fahrzeit_min = 0;
    printf("Gefahrene Minuten: ");
    scanf("%lf", &fahrzeit_min);

    double gefahrene_km = 0;
    printf("Gefahrene Kilometer: ");
    scanf("%lf", &gefahrene_km);

    double gebrauchte_liter = 0;
    printf("Gebrauchte Liter: ");
    scanf("%lf", &gebrauchte_liter);

    fahrzeit_h += fahrzeit_min / 60; // minuten zu stunden
    double durchschnittsgeschwindigkeit = gefahrene_km / fahrzeit_h; // km/h
    double durchschnittsbenzinverbrauch = (gebrauchte_liter * 100) / gefahrene_km; // l/100km

    printf("Durchschnittl. Geschwindigkeit: %.2lf km/h (%.2lf m/s)\n", durchschnittsgeschwindigkeit, durchschnittsgeschwindigkeit / 3.6);
    printf("Durchschnittl. Benzinverbrauch: %.2lf l/100 km\n", durchschnittsbenzinverbrauch);

    return 0;
}