/* Erstellen Sie ein C-Programm zahlrat.c, das sich zufällig eine Zahl aus dem Intervall [1,x] denkt.
 * x ist dabei vom Benutzer einzugeben. Danach soll der Benutzer versuchen, die vom Computer
 * gedachte Zahl zu erraten. Für jeden Rateversuch wird dem Benutzer mitgeteilt, ob seine Zahl
 * zu groß oder zu klein ist.
 * Möglicher Ablauf dieses Programms zahlrat.c:
 *    Ich denke mir eine Zahl aus dem Intervall [1,x].
 *    Du musst dann versuchen, diese Zahl zu erraten.
 *
 *    Zunaechst musst du einmal festlegen,
 *    wie gross die zu ratende Zahl maximal sein darf: 40 ↩
 *
 *    Hm..... OK, ich habe eine Zahl
 *
 *    Dein 1.Versuch: 20 ↩
 *        .....zu niedrig
 *    Dein 2.Versuch: 30 ↩
 *        ........zu hoch
 *    Dein 3.Versuch: 25 ↩
 *        .....zu niedrig
 *    Dein 4.Versuch: 28 ↩
 *        ........zu hoch
 *    Dein 5.Versuch: 26 ↩
 *        .....zu niedrig
 *    Dein 6.Versuch: 27 ↩
 *        .....Richtig
 *
 *    Du hast 6 Versuche zum Erraten der Zahl benötigt.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

long map(long x, long in_min, long in_max, long out_min, long out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main() {
    printf("Ich denke mir eine Zahl aus dem Intervall [1,x].\n"
           "Du musst dann versuchen, diese Zahl zu erraten.\n\n"
           "Zunaechst musst du einmal festlegen,\n"
           "wie gross die zu ratende Zahl maximal sein darf: ");

    int intervall_max = -1;
    scanf_number(&intervall_max);

    while (intervall_max < 1) {
        printf("das Intervallmaximum muss größer gleich 1 sein!");
        scanf_number(&intervall_max);
    }


    srand(time(nullptr));  // seed rand() with current time

    // zufällige Zahl zwischen 1 und intervall_max
    int zufallszahl = map(rand(), 0, RAND_MAX, 1, intervall_max);
    printf("\nHm..... OK, ich habe eine Zahl\n");
    printf("\nDEBUG: zahl = %i\n", zufallszahl);


    int count = 0;
    int eingabe = 0;
    do {
        count ++;
        printf("\nDein %i. Versuch: ", count);
        scanf_number(&eingabe);

        if (eingabe < zufallszahl)
            printf("    .....zu niedrig\n");
        else if (eingabe > zufallszahl)
            printf("    ........zu hoch\n");

    } while (eingabe != zufallszahl);
    printf("    .......richtig!\n");

    printf("\n\nDu hast %i Versuche zum Erraten der Zahl benötigt.\n", count);

    return 0;
}
