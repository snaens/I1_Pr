/*
 * Erstellen Sie ein C-Programm, dass mit scanf() den Radius einer Kugel einliest und dann
 * den Umfang (2rπ), das Volumen (4/3 r^3 π) und die Oberfläche (4π r^2) dieser Kugel ausgibt. Dabei
 * sollten Sie die Konstanten für π und 4π definieren. Nachfolgend sind Beispiele für mögliche
 * Programmabläufe gegeben.
 *    Radius der Kugel : 3 ↩
 *    Umfang=18.849556
 *    Volumen=113.097336
 *    Oberflaeche=113.097336
 *
 *    Radius der Kugel : 34.5 ↩
 *    Umfang=216.769897
 *    Volumen=172006.906250
 *    Oberflaeche=14957.123047
 */

#include <math.h>
#include <stdio.h>

int main () {
    printf("Radius der Kugel: ");
    float radius;

    const float pi = M_PI;
    const float pi_4 = pi * 4;

    scanf("%f", &radius);
    printf("Unfang=%.2f\n", 2 * radius * pi);
    printf("Volumen=%.2f\n", (4/3.f) * pow(radius, 3) * pi );
    printf("Volumen=%.2f\n", pow(radius, 2) * pi_4);
}