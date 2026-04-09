/* Erstellen Sie ein Programm, das eine gerade Zahl zwischen 1 und 100 einliest, die Eingabe
 * überprüft und bei falschen Eingaben zur Wiederholung auffordert. Nach korrekter Eingabe ist
 * die entsprechende Zahl auszugeben.
 */

#include <stdio.h>
int main() {
    printf("Eingabe: ");
    int eingabe = 0;
    int scanf_ret = -1;

    while (eingabe < 1 || eingabe > 100 || eingabe % 2 != 0 || scanf_ret != 1) {
        scanf_ret = scanf("%i", &eingabe);

        while (getchar() != '\n'); // puffer entleeren -> fehlerhafte Eingabe macht manchmal quatsch in dne Puffer

        if (scanf_ret != 1) {
            printf("Fehlerhafte eingabe, probiere nochmals: ");
        } else if (eingabe < 1 || eingabe > 100 || eingabe % 2 != 0) {
            printf("    Die Eingabe %i liegt nicht im Bereich 1...100.\nErneute Eingabe: ", eingabe);
        }
    }
    printf("    Eingabe war: %i\n", eingabe);
}