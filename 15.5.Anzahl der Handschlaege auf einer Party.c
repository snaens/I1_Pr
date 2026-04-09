/* Dies ist die altbekannte Geschichte vom Händeschütteln. n Personen treffen sich auf einer Party.
 * Jeder schüttelt dabei jedem die Hände. Wieoft werden insgesamt Hände geschüttelt. Wenn z.B.
 * 10 Personen auf der Party sind, so schüttelt die erste Person 9 anderen Personen die Hand, die
 * zweite noch 8 anderen, die dritte 7 anderen usw.
 * Erstellen Sie ein C-Programm party.c, das einliest, wie viele Personen auf der Party sind, und
 * dann ausgibt, wieoft Hände auf dieser Party geschüttelt werden.
 * Mögliche Abläufe dieses Programms party.c:
 *    Haendeschuetteln aller Personen auf einer Party
 *    ===============================================
 *    Wieviele Personen sind auf der Party: 10 ↩
 *    Es werden 45 mal die Haende geschuettelt
 *
 *    ........
 *    Wieviele Personen sind auf der Party: 100 ↩
 *    Es werden 4950 mal die Haende geschuettelt
 *
 *    ........
 *    Wieviele Personen sind auf der Party: 500 ↩
 *    Es werden 124750 mal die Haende geschuettelt
 */

#include <stdio.h>

int main() {
    printf("Haendeschuetteln aller Personen auf einer Party\n"
           "===============================================\n"
           "Wieviele Personen sind auf der Party: ");
    int n;
    scanf("%d", &n);

    int geschuettelte_haende_ingesamt = 0;
    for (int i = n; i > 0; i--) { // personen iterieren [n..1]
        for (int j = i - 1; j > 0; j--) { // schüttler iterieren [i-1..1]
            geschuettelte_haende_ingesamt++;
        }
    }

    printf("Es werden %d mal die Haende geschuettelt\n", geschuettelte_haende_ingesamt);
}
