/* Erstellen Sie ein C-Programm vumrech.c, das eine zurückgelegte Strecke (in Meter) und die dafür
 * benötigte Zeit (in Sekunden) einliest, bevor es dann die Geschwindigkeit in m/s, km/h, km/tag
 * und m/tag ausgibt. Die Umrechnungsfaktoren sollten Sie dabei in der eigenen Headerdatei
 * faktor.h definieren:
 *    #define MS_NACH_KMH ......
 *    #define MS_NACH_KMTAG ......
 *    #define MS_NACH_MTAG ......
 *
 * Diese Umrechnungsfaktoren sollten Sie dann in Ihrem Programm vumrech.c verwenden. Um
 * dies tun zu können, müssen Sie dort aber Folgendes angeben:
 *    #include "faktor.h"
 *
 * Mögliche Abläufe dieses Programms vumrech.c:
 *    Gib Strecke ein (in Meter): 1 ↩
 *    Gib Zeit ein, die dafuer benoetigt wird (in Sekunden): 1 ↩
 *    Dies entspricht folgender Geschwindigkeit:
 *    1.000000 m/sec =
 *    3.600000 km/h =
 *    86400.000000 m/Tag =
 *    86.400002 km/Tag
 *
 *    Gib Strecke ein (in Meter): 123 ↩
 *    Gib Zeit ein, die dafuer benoetigt wird (in Sekunden): 3.5 ↩
 *    Dies entspricht folgender Geschwindigkeit:
 *    35.142857 m/sec =
 *    126.514282 km/h =
 *    3036342.750000 m/Tag =
 *    3036.342773 km/Tag
 */

#include <stdio.h>

#include "7.1.1.Umrechnung von Geschwindigkeiten.h"

int main() {
    float in_meter;
    printf("Gib Strecke ein (in Meter): ");
    scanf("%f", &in_meter);

    float in_sekunden;
    printf("Gib Zeit ein, die dafuer benoetigt wird (in Sekunden): ");
    scanf("%f", &in_sekunden);

    printf("Dies entspricht folgender Geschwindigkeit:\n");
    float mps = in_meter / in_sekunden;
    printf("%f m/sec =\n", mps);
    printf("  %f km/h =\n", mps * MS_NACH_KMH);
    printf("    %f m/Tag =\n", mps * MS_NACH_MTAG);
    printf("      %f km/Tag =\n", mps * MS_NACH_KMTAG);

    return 0;
}