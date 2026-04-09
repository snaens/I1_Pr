/* Erstellen Sie ein C-Programm flaeche.c, bei dem der Benutzer wählen kann, welche der folgen-
 * den Flächen er sich berechnen lassen möchte:
 *     Quadrat: A = a · a (a ist die einzugebende Seitenlänge)
 *     Rechteck: A = a · b (a und b sind die einzugebenden Seitenlängen)
 *     Kreis: A = a · a · π (a ist der Radius des Kreises)
 *     Ellipse: A = a · b · π (a ist Radius der x- und b Radius der y-Achse der Ellipse)
 * An dieser Formel für die Ellipse ist zu erkennen, dass eine Ellipse zu einem Kreis degeneriert,
 * wenn a und b gleich sind.
 *
 * Mögliche Abläufe dieses Programms flaeche.c:
 *    Quadrat: q
 *    Rechteck: r
 *    Kreis: k
 *    Ellipse: e
 *    Deine Wahl? q ↩
 *    Seitenlaenge des Quadrats: 21.4 ↩
 *    ...... Flaeche = 457.96
 *
 *    Quadrat: q
 *    Rechteck: r
 *    Kreis: k
 *    Ellipse: e
 *    Deine Wahl? ↩
 *    Radius der x-Achse: 12.3 ↩
 *    Radius der y-Achse: 5.6 ↩
 *    ...... Flaeche = 216.39
 *
 *    Quadrat: q
 *    Rechteck: r
 *    Kreis: k
 *    Ellipse: e
 *    Deine Wahl? r ↩
 *    Laenge der 1. Rechteckseite: 7 ↩
 *    Laenge der 2. Rechteckseite: 8 ↩
 *    ...... Flaeche = 56.00
 *
 *    Quadrat: q
 *    Rechteck: r
 *    Kreis: k
 *    Ellipse: e
 *    Deine Wahl? x ↩
 *    ......’x’ ist keine erlaubte Wahl
 */

#include <math.h>
#include <stdio.h>

int main() {
    printf("Quadrat: q\n"
           "Rechteck: r\n"
           "Kreis: k\n"
           "Ellipse: e\n"
           "Deine Wahl? ");
    unsigned char wahl = 0;
    scanf("%c", &wahl);

    switch (wahl) {
        case 'q':
            printf("Seitenlaenge des Quadrats: ");
            float seitenlaenge = 0;
            scanf("%f", &seitenlaenge);
            printf("\n...... Flaeche = %f", seitenlaenge * seitenlaenge);
            break;
        case 'r':
            printf("Laenge der 1. Rechteckseite:  ");
            float l1 = 0;
            scanf("%f", &l1);
            printf("Laenge der 1. Rechteckseite:  ");
            float l2 = 0;
            scanf("%f", &l2);
            printf("\n...... Flaeche = %f", l1 * l2);
            break;
        case 'k':
            printf("Radius der x-Achse: ");
            float rad = 0;
            scanf("%f", &rad);
            printf("\n...... Flaeche = %f", rad * rad * M_PI);
            break;
        case 'e':
            printf("Radius der x-Achse: ");
            float radx = 0;
            scanf("%f", &radx);
            printf("Radius der y-Achse: ");
            float rady = 0;
            scanf("%f", &rady);
            printf("\n...... Flaeche = %f", radx * rady * M_PI);
            break;
        default:
            printf("......'%c' ist keine erlaubte Wahl", wahl);
    }
}
