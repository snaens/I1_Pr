/* Die Zahl π läßt sich auf sechs Stellen genau mit der folgenden Kettenbruchentwicklung berechnen:
 *
 * Ergänzen Sie nun das folgende C-Programm kettenpi.c, indem sie diesen Kettenbruch in einen
 * C-Ausdruck umwandeln, den Sie der Variablen pi zuweisen.
 */

/*---- kettenpi.c -------------------------------------------------*/
/*-----------------------------------------------------------------*/
#include <stdio.h>

int main(void) {
    float pi;
    pi = 1.f / (1.f / (1.f / (1.f / (1.f / 2 + 292) + 1) + 15) + 7) + 3;
    printf("Pi = %f\n", pi);
    return 0;
}
