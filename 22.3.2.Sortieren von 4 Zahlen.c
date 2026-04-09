/* Erstellen Sie ein Programm sort4zah.c, das vier ganze Zahlen einliest und diese aufsteigend
 * sortiert. Der Anwender soll dabei den Vorgang des Sortierens mitverfolgen können, wie z.B.:
 *
 * 1. Ablaufbeispiel:
 *    Sortieren von 4 Integer Zahlen
 *    ===============================
 *      Zahl1?: 1 ↩
 *      Zahl2?: 2 ↩
 *      Zahl3?: 3 ↩
 *      Zahl4?: 4 ↩
 *    Was soll das?!
 *    Die Zahlen sind bereits sortiert!!
 *
 * 2. Ablaufbeispiel:
 *    Sortieren von 4 Integer Zahlen
 *    ===============================
 *      Zahl1?: 7 ↩
 *      Zahl2?: 5 ↩
 *      Zahl3?: 3 ↩
 *      Zahl4?: 1 ↩
 *    1. Durchlauf - Aktueller Stand:
 *      Zahl1: 5
 *      Zahl2: 3
 *      Zahl3: 1
 *      Zahl4: 7
 *    Weiter mit Return... ↩
 *    2. Durchlauf - Aktueller Stand:
 *      Zahl1: 3
 *      Zahl2: 1
 *      Zahl3: 5
 *      Zahl4: 7
 *    Weiter mit Return... ↩
 *    3. Durchlauf - Aktueller Stand:
 *      Zahl1: 1
 *      Zahl2: 3
 *      Zahl3: 5
 *      Zahl4: 7
 *    Weiter mit Return... ↩
 *
 *
 *    !!!! FERTIG nach 3 Durchlaeufen !!!!!
 *
 * 3. Ablaufbeispiel:
 *     Sortieren von 4 Integer Zahlen
 *     ===============================
 *       Zahl1?: 1 ↩
 *       Zahl2?: 4 ↩
 *       Zahl3?: 7 ↩
 *       Zahl4?: 2 ↩
 *     1. Durchlauf - Aktueller Stand:
 *       Zahl1: 1
 *       Zahl2: 4
 *       Zahl3: 2
 *       Zahl4: 7
 *     Weiter mit Return... ↩
 *     2. Durchlauf - Aktueller Stand:
 *       Zahl1: 1
 *       Zahl2: 2
 *       Zahl3: 4
 *       Zahl4: 7
 *     Weiter mit Return... ↩
 *
 *     !!!! FERTIG nach 2 Durchlaeufen !!!!!
 */

#include <limits.h>
#include <stdio.h>

#define MENGE_ZAHLEN 4


// iteration schiebt den Zeiger auf dem Array nach links
// verwendung: trennung was bereits fertig sortiert wurde
bool sortiervorgang(int (*zahlen)[MENGE_ZAHLEN]) {

    // wo müssen wir weiter sortieren
    int index_limit = MENGE_ZAHLEN - 1;
    while (((*zahlen)[index_limit] > (*zahlen)[index_limit - 1]) && index_limit > 0) {
        index_limit--;
    }
    if (index_limit == 0) return true; // alle Zahlen bereits sortiert!

    int index_maxwert = -1;
    int maxwert = INT_MIN;
    // finde den Maximalwert und dessen Index im Intervall [0..index]
    for (int i = 0; i <= index_limit; i++) {
        if ((*zahlen)[i] > maxwert) {
            maxwert = (*zahlen)[i];
            index_maxwert = i;
        }
    }

    // es gab eine nicht-sortierte Zahl
    if (index_maxwert != -1) {
        // tausche Zahlen aus
        int buf = (*zahlen)[index_limit]; // wert, der gerade den max-slot besetzt
        (*zahlen)[index_limit] = (*zahlen)[index_maxwert]; // kopiere den maximalen Wert da rein
        (*zahlen)[index_maxwert] = buf; // kopiere den besetzer-wert zu wo der maximalwert drin war
        return false;
    } else // fertig sortiert!
        return true;
}

int scanf_number(int* eingabe) {
    int scanf_ret = -1;

    while (scanf_ret != 1) {
        scanf_ret = scanf("%d", eingabe);

        while (getchar() != '\n'); // puffer entleeren -> fehlerhafte Eingabe macht manchmal quatsch in dne Puffer

        if (scanf_ret != 1) {
            printf("Fehlerhafte eingabe, probiere nochmals: ");
        }
    }
}

int main() {
    int zahlen[MENGE_ZAHLEN];

    printf("Sortieren von 4 Integer Zahlen\n"
           "===============================\n");

    // Eingabe
    for (int i = 0; i < MENGE_ZAHLEN; i++) {
        printf("  Zahl%d: ", i + 1);
        scanf_number(&zahlen[i]);
    }

    int iteration = 0;
    while (true) {
        printf("%d. Durchlauf - Aktueller Stand:\n", iteration);
        for (int i = 0; i < MENGE_ZAHLEN; i++) {
            printf("  Zahl%d: %d\n", i + 1, zahlen[i]);
        }

        if (sortiervorgang(&zahlen))
            break;

        printf("Weiter mit Return...");
        while ((getchar()) != '\n')
            ; // auf '\n' warten
        iteration++;
    }
    if (iteration == 0)
        printf("\nWas soll das?!\n"
               "Die Zahlen sind bereits sortiert!!\n");
    else
        printf("\n!!!! FERTIG nach %d Durchlaeufen !!!!!\n", iteration);
}
