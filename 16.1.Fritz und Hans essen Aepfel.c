/* Fritz und Hans haben gemeinsam x Äpfel gekauft. In der Zeit, in der Fritz 5 Äpfel ißt, ißt Hans 3.
 * Wie viele Äpfel hat jeder gegessen, wenn keine mehr übrig sind. Erstellen Sie ein C-Programm
 * aepfel.c, das zunächst einliest, wie viele Äpfel Fritz und Hans zusammen gekauft haben, und
 * dann die in jeder Runde von Fritz bzw. Hans gegessenen Äpfel einschließlich der noch übrigen
 * Äpfel in Form einer Tabelle ausgibti, wie z. B.:
 *
 *    Wieviele Aepfel haben Fritz und Hans gekauft: 114 ↩
 *    Sorry, aber die Zahl der Aepfel muss durch 8 teilbar sein
 *    Gib eine neue Zahl ein: 122 ↩
 *    Sorry, aber die Zahl der Aepfel muss durch 8 teilbar sein
 *    Gib eine neue Zahl ein: 120 ↩
 *    | Runde | Fritz | Hans  | Rest  |
 *    |-------+-------+-------+-------|
 *    | 1     | 5     | 3     | 112   |
 *    | 2     | 10    | 6     | 104   |
 *    | 3     | 15    | 9     | 96    |
 *    | 4     | 20    | 12    | 88    |
 *    | 5     | 25    | 15    | 80    |
 *    | 6     | 30    | 18    | 72    |
 *    | 7     | 35    | 21    | 64    |
 *    | 8     | 40    | 24    | 56    |
 *    | 9     | 45    | 27    | 48    |
 *    | 10    | 50    | 30    | 40    |
 *    | 11    | 55    | 33    | 32    |
 *    | 12    | 60    | 36    | 24    |
 *    | 13    | 65    | 39    | 16    |
 *    | 14    | 70    | 42    | 8     |
 *    | 15    | 75    | 45    | 0     |
 */

#include <stdio.h>
int main() {
    printf("Wieviele Aepfel haben Fritz und Hans gekauft: ");
    int aepfel_ges = 0;
    int scanf_ret = -1;

    while (aepfel_ges % 8 != 0 || scanf_ret != 1) {
        scanf_ret = scanf("%d", &aepfel_ges);

        while (getchar() != '\n'); // puffer entleeren -> fehlerhafte Eingabe hinterlässt manchmal quatsch im Puffer

        if (scanf_ret != 1) {
            printf("invalide eingabe, probiere nochmals: ");
        } else if (aepfel_ges % 8 != 0) {
            printf("Sorry, aber die Zahl der Aepfel muss durch 8 teilbar sein\n"
                "Gib eine neue Zahl ein: ");
        }
    }

    printf("\n| Runde | Fritz | Hans  | Rest  |\n"
        "|-------+-------+-------+-------|\n");
    int fritz_gegessne = 0;
    int hans_gegessne = 0;
    for (int i = 0; aepfel_ges > 0; i++) {
        fritz_gegessne += 5;
        hans_gegessne += 3;
        aepfel_ges -= 8;
        printf("| %-6d| %-6d| %-6d| %-6d|\n", i+1,  fritz_gegessne, hans_gegessne, aepfel_ges);
    }
}