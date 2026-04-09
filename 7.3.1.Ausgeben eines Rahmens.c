/* Erstellen Sie ein C-Programm rahmen.c, das einen Rahmen am Bildschirm ausgibt. Der Rahmen
 * soll immer 5 Zeilen lang sein. Wie breit er sein soll, soll der Benutzer eingeben.
 *
 * Hinweis für alle, die schon C-Vorkenntnisse haben:
 * Das Programm muss ohne Schleifen gelöst werden!
 *
 *    Wie breit soll Rahmen werden: 5 ↩
 *    +-----+
 *    |     |
 *    |     |
 *    |     |
 *    +-----+
 *
 *    Wie breit soll Rahmen werden: 45 ↩
 *    +---------------------------------------------+
 *    |                                             |
 *    |                                             |
 *    |                                             |
 *    +---------------------------------------------+
 *
 *    Wie breit soll Rahmen werden: 75 ↩
 *    +---------------------------------------------------------------------------+
 *    |                                                                           |
 *    |                                                                           |
 *    |                                                                           |
 *    +---------------------------------------------------------------------------+
 */

#include <stdio.h>

// recursively fill array from top to bottom
void fill_with_x(char *buf, int pos, char c) {
    if (pos >= 0) {
        buf[pos] = c; // arrays fangen bei 0 an
        fill_with_x(buf, --pos, c);
    }
}

int main() {
    int breite = 2;
    printf("Wie breit soll Rahmen werden: ");
    scanf("%d", &breite);
    if (breite < 2)
        return 1; // Rahmen kann nicht weniger als 2 char breit werden

    breite = breite - 2; // innenbreite

    char line_buf[breite + 1]; // +1 für null element am Ende
    line_buf[breite] = '\0'; // c-style string (-1 wegen 0-index von Arrays)
    fill_with_x(line_buf, breite - 1, '-');
    printf("+%s+\n", line_buf); // Obere Zeile
    fill_with_x(line_buf, breite - 1, ' ');
    printf("|%s|\n", line_buf); // Innenzeile
    printf("|%s|\n", line_buf); // Innenzeile
    printf("|%s|\n", line_buf); // Innenzeile
    fill_with_x(line_buf, breite - 1, '-');
    printf("+%s+\n", line_buf); // Untere Zeile
    return 0;
}
