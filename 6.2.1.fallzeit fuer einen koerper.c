/* Erstellen Sie ein C-Programm fallzeit.c, das die Zeit berechnet, die ein Körper wie z.B. ein Stein
 * für den Fall aus einer bestimmten Höhe benötigt. Die Höhe ist dabei mit scanf() einzulesen.
 * Bei diesem Programm sollten Sie die Gravitations-Konstante g (g = 9.80665 m/s^2 ) mit const defi-
 * snieren. Die Zeit für den Fall eines Körpers läßt sich nach folgender Formel berechnen:
 *    t = − sqrt(2h/g)
 * Das zur Wurzelberechnung benötigte Programmteil hat den Namen sqrt(). Damit Sie sqrt()
 * verwenden können, sollten Sie in Ihrem Programm fallzeit.c als erstes die folgende Zeile angeben:
 *    #include <math.h>
 * und das Kompilieren und Linken des Programms mit folgender Kommandozeile durchführen:
 *    cc -o fallzeit fallzeit.c -lm
 * Beispiel für mögliche Programmabläufe:
 *    Hoehe des Koerpers (in Meter): 100 ↩
 *    --->Fallzeit: 4.516007 Sek.
 *    Hoehe des Koerpers (in Meter): 1000 ↩
 *    ---> Fallzeit: 14.280869 Sek.
 */

#include <math.h>
#include <stdio.h>

int main() {
    printf("Hoehe des Koerpers (in Meter): ");
    double hoehe_m = 0.f;
    scanf("%lf", &hoehe_m);

    const double gravitationskonstante = 9.80665; // m/s^2

    printf("---> Fallzeit: %lf Sek.", sqrt((2 * hoehe_m) / gravitationskonstante));
}
