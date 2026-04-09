/* Erstellen Sie ein C-Programm primzahl.c, das alle Primzahlen zwischen m und n ermittelt und
 * ausgibt. m und n sind dabei einzugeben.
 *
 * Mögliche Abläufe dieses Programms primzahl.c sind z.B.:
 *
 *     Primzahlen
 *     ==========
 *     Dieses Programm gibt Ihnen alle Primzahlen zwischen
 *     m und n aus. m und n sind dabei einzugeben.
 *     m: 1 ↩
 *     n: 500 ↩
 *     2,      5,    3,    7,   11,   13,   17,   19,
 *     23,    29,   31,   37,   41,   43,   47,   53,
 *     59,    61,   67,   71,   73,   79,   83,   89,
 *     97,   101,  103,  107,  109,  113,  127,  131,
 *     137,  139,  149,  151,  157,  163,  167,  173,
 *     179,  181,  191,  193,  197,  199,  211,  223,
 *     227,  229,  233,  239,  241,  251,  257,  263,
 *     269,  271,  277,  281,  283,  293,  307,  311,
 *     313,  317,  331,  337,  347,  349,  353,  359,
 *     367,  373,  379,  383,  389,  397,  401,  409,
 *     419,  421,  431,  433,  439,  443,  449,  457,
 *     461,  463,  467,  479,  487,  491,  499,
 *
 *     ........
 *     m: 12345000 ↩
 *     n: 12345500 ↩
 *     12345001, 12345017, 12345049, 12345071, 12345083, 12345121, 12345127, 12345143,
 *     12345149, 12345163, 12345169, 12345191, 12345209, 12345211, 12345233, 12345253,
 *     12345259, 12345283, 12345293, 12345301, 12345313, 12345317, 12345323, 12345341,
 *     12345367, 12345371, 12345373, 12345379, 12345397, 12345413, 12345419, 12345427,
 *     12345433, 12345439, 12345479, 12345491, 12345493, 12345499,
 */

#include <stdio.h>

#define LINEBREAK_AFTER 8 // numbers printed

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
    printf("Primzahlen\n"
           "==========\n"
           "Dieses Programm gibt Ihnen alle Primzahlen zwischen\n"
           "m und n aus. m und n sind dabei einzugeben.\n");

start_eingabe:
    printf("m: ");
    int m = 0;
    scanf_number(&m);

    printf("n: ");
    int n = 0;
    scanf_number(&n);

    if (m>n) {
        printf("m darf nicht kleiner n sein!\n" "probiere nochmals\n");
        goto start_eingabe;
    }


    int numbers_printed = 0;
    // alle Zahlen von `m` nach `n` hochzählen
    for (long i = m; i <= n; i++) {
        // Durchchecken ob `i` eine Primzahl ist
        for (long j = i - 1; j > 0; j--) {
            if (j != 1) {
                if (i % j == 0) break; // teiler gefunden - keine Primzahl!
            } else { // teiler `1` erreicht & kein sauberer Teiler - Primzahl!
                printf("%8ld,", i);
                numbers_printed++;
            }
        }

        // Formatierung: Zeilenumbruch nach `LINEBREAK_AFTER` gedruckten Zahlen
        if (numbers_printed == LINEBREAK_AFTER) {
            printf("\n");
            numbers_printed = 0;
        }
    }
    return 0;
}
