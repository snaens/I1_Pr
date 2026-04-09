/* Die Höhe, bei der ein Fallschirmspringer spätestens seine Reißleine ziehen muss, um unver-
 * sehrt zu landen, beträgt etwa 650 Meter. Erstellen Sie ein C-Programm falschir.c, das die Ab-
 * sprunghöhe als Ganzzahl einliest und dann ausgibt, wie viele Sekunden (als Ganzzahl) dem
 * Fallschirmspringer bleiben, bis er die Reißleine ziehen muss.
 *
 * Mögliche Abläufe dieses Programms falschir.c:
 *    In welcher Hoehe verlaesst der Fallschirmspringer den Flieger: 3400 ↩
 *    ---> Springer muss nach 23 Sekunden die Reissleine ziehen
 *
 *    In welcher Hoehe verlaesst der Fallschirmspringer den Flieger: 45000 ↩
 *    ---> Springer muss nach 95 Sekunden die Reissleine ziehen
 */

#include <stdio.h>
#include <math.h>

#define GRAVITATION_KONSTANTE 9.81 // m/s^2

int main() {
    printf("In welcher Hoehe verlaesst der Fallschirmspringer den Flieger: ");
    int sprunghoehe = 0;
    scanf("%d", &sprunghoehe);

    int fallschirm_zeit = sqrt(2 * (sprunghoehe - 650.f) / GRAVITATION_KONSTANTE);
    printf("---> Springer muss nach %d Sekunden die Reissleine ziehen\n", fallschirm_zeit);
}
