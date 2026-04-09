/* Erstellen Sie ein Programm strekzug.c, das die Länge eines Streckenzuges durch die nacheinan-
 * der angegebenen Punkte eines Koordinatensystems ermittelt.
 * Mögliche Abläufe dieses Programms strekzug.c:
 *
 *     Strecken-Berechnungen
 *     =======================
 *     Bitte Startpunkt eingeben (x,y): 5,3 ↩
 *     Neuer Streckenpunkt x,y (Abbruch mit x=-1): 2,4 ↩
 *     Neuer Streckenpunkt x,y (Abbruch mit x=-1): 7,9 ↩
 *     Neuer Streckenpunkt x,y (Abbruch mit x=-1): -1 ↩
 *     => Die Streckenlaenge betraegt: 10.23 Einheiten
 *
 *     Strecken-Berechnungen
 *     =======================
 *     Bitte Startpunkt eingeben (x,y): 0,0
 *     Neuer Streckenpunkt x,y (Abbruch mit x=-1): 4,2 ↩
 *     Neuer Streckenpunkt x,y (Abbruch mit x=-1): 3,-1 ↩
 *     Neuer Streckenpunkt x,y (Abbruch mit x=-1): 1,3 ↩
 *     Neuer Streckenpunkt x,y (Abbruch mit x=-1): -1 ↩
 *     => Die Streckenlaenge betraegt: 12.11 Einheiten
 */

#include <math.h>
#include <stdio.h>

struct koordinate {
    double x;
    double y;
};

bool scanf_koordinate(struct koordinate* eingabe) {
    int scanf_ret = -1;

    while (scanf_ret != 2) {
        scanf_ret = scanf("%lf,%lf", &eingabe->x, &eingabe->y);

        while (getchar() != '\n'); // puffer entleeren -> fehlerhafte Eingabe macht manchmal quatsch in dne Puffer

        if (scanf_ret == 1 && eingabe->x == -1.0) {
            return true; // = abbruchvorgang
        }
        if (scanf_ret != 2) {
            printf("Fehlerhafte eingabe, probiere nochmals: ");
        }
    }
    return false;
}

double strecke_zwischen(struct koordinate a, struct koordinate b) {
    struct koordinate b_rel = {b.x - a.x, b.y - a.y};

    // c = sqrt(a^2 + b^2)
    return sqrt(b_rel.x * b_rel.x + b_rel.y * b_rel.y);
}

int main() {
    struct koordinate jetztige_endpos; // jetztiger Endpunkt der Strecke
    double length = 0; //
    printf("Strecken-Berechnungen\n"
           "=======================\n"
           "Bitte Startpunkt eingeben (x,y): ");
    scanf_koordinate(&jetztige_endpos);

    while (true) {
        struct koordinate eingabe = {-1, -1};
        printf("Neuer Streckenpunkt x,y (Abbruch mit x=-1): ");
        if (scanf_koordinate(&eingabe))
            break; // verhindern, dass der Abbruchwert (-1) dazugerechnet wird
        length += strecke_zwischen(jetztige_endpos, eingabe);
        jetztige_endpos = eingabe;
    }

    printf("=> Die Streckenlaenge betraegt: %.2lf Einheiten", length);
    return 0;
}
