/* Auf einem quadratischen Spielfeld mit n x n Feldern setzen zwei Spieler abwechselnd je einen
 * Stein ihrer Farbe (X oder O). Wer zuerst 3 Steine in einer Reihe, Spalte oder Diagonale setzen
 * kann, gewinnt das Spiel. Erstellen Sie ein C-Programm tictac.c, das dieses Spiels simuliert und
 * schließlich den Gewinner ausgibt, wie z.B.:
 *     Spielfeldgroesse (mind. 3, maximal 10) ? 5 ↩
 *     Dein Zug, Spieler 1 (Zeile,Spalte) ? 2,3 ↩
 *     1 . . . . .
 *     2 . . X . .
 *     3 . . . . .
 *     4 . . . . .
 *     5 . . . . .
 *     Dein Zug, Spieler 2 (Zeile,Spalte) ? 3,4 ↩
 *     1 . . . . .
 *     2 . . X . .
 *     3 . . . O .
 *     4 . . . . .
 *     5 . . . . .
 *     Dein Zug, Spieler 1 (Zeile,Spalte) ? 2,4 ↩
 *     1 . . . . .
 *     2 . . X X .
 *     3 . . . O .
 *     4 . . . . .
 *     5 . . . . .
 *     Dein Zug, Spieler 2 (Zeile,Spalte) ? 2,3 ↩
 *     ....Unerlaubter Spielzug
 *     Dein Zug, Spieler 2 (Zeile,Spalte) ? 2,2 ↩
 *     1 . . . . .
 *     2 . O X X .
 *     3 . . . O .
 *     4 . . . . .
 *     5 . . . . .
 *     Dein Zug, Spieler 1 (Zeile,Spalte) ? 2,5 ↩
 *     1 . . . . .
 *     2 . O X X X
 *     3 . . . O .
 *     4 . . . . .
 *     5 . . . . .
 *     Spieler 1 hat gewonnen
 */
#include <stdio.h>

enum feldkasten {
    NoP = '.', // No Player
    P1 = 'X', // Player1
    P2 = 'O', // Player2
};


int scanf_koordinate(int* eingabex, int* eingabey) {
    int scanf_ret = -1;
    while (scanf_ret != 2) {
        scanf_ret = scanf("%d,%d", eingabex, eingabey);

        while (getchar() != '\n'); // puffer entleeren -> fehlerhafte Eingabe macht manchmal quatsch in den Puffer

        if (scanf_ret != 2) {
            printf("Fehlerhafte eingabe, probiere nochmals: ");
        }
    }
}

int scanf_sizet(int* eingabe) {
    int scanf_ret = -1;
    while (scanf_ret != 1) {
        scanf_ret = scanf("%d", eingabe);

        while (getchar() != '\n'); // puffer entleeren -> fehlerhafte Eingabe macht manchmal quatsch in den Puffer

        if (scanf_ret != 1) {
            printf("Fehlerhafte eingabe, probiere nochmals: ");
        }
    }
}

void print_spielfeld(int spielfeldgroesse, enum feldkasten (*spielfeld)[spielfeldgroesse][spielfeldgroesse]) {
    // kasten + legende y
    for (int x = spielfeldgroesse - 1; x >= 0; x--) {
        printf(" %d ", x);
        for (int y = 0; y < spielfeldgroesse; y++) {
            printf(" %c", (*spielfeld)[x][y]);
        }
        printf("\n");
    }
    // legende x
    printf("y/x ");
    for (int i = 0; i < spielfeldgroesse; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

enum feldkasten gewinn_checker(size_t spielfeldgroesse, enum feldkasten (*spielfeld)[spielfeldgroesse][spielfeldgroesse]) {
    // vertikale 3-er Reihen
    for (int x = 0; x < spielfeldgroesse; x++) {
        for (int y = 0; y < spielfeldgroesse - 2; y++) { //-2 weil reihe kann nicht übers Spielfeld hinaus
            if ((*spielfeld)[x][y] == P1 && (*spielfeld)[x][y + 1] == P1 && (*spielfeld)[x][y + 2] == P1)
                return P1;
            if ((*spielfeld)[x][y] == P2 && (*spielfeld)[x][y + 1] == P2 && (*spielfeld)[x][y + 2] == P2)
                return P2;
        }
    }
    // horizontale 3-er Reihen
    for (int x = 0; x < spielfeldgroesse - 2; x++) {
        for (int y = 0; y < spielfeldgroesse; y++) { //-2 weil reihe kann nicht übers Spielfeld hinaus
            if ((*spielfeld)[x][y] == P1 && (*spielfeld)[x + 1][y] == P1 && (*spielfeld)[x + 2][y] == P1)
                return P1;
            if ((*spielfeld)[x][y] == P2 && (*spielfeld)[x + 1][y] == P2 && (*spielfeld)[x + 2][y] == P2)
                return P2;
        }
    }
    // diagonale-steigend 3-er Reihen
    for (int x = 0; x < spielfeldgroesse - 2; x++) { //-2 weil reihe kann nicht übers Spielfeld hinaus
        for (int y = 0; y < spielfeldgroesse - 2; y++) { //-2 weil reihe kann nicht übers Spielfeld hinaus
            if ((*spielfeld)[x][y] == P1 && (*spielfeld)[x + 1][y + 1] == P1 && (*spielfeld)[x + 2][y + 2] == P1)
                return P1;
            if ((*spielfeld)[x][y] == P2 && (*spielfeld)[x + 1][y + 1] == P2 && (*spielfeld)[x + 2][y + 2] == P2)
                return P2;
        }
    }
    // diagonale-sinkend 3-er Reihen
    for (int x = 0; x < spielfeldgroesse - 2; x++) { //-2 weil reihe kann nicht übers Spielfeld hinaus
        for (int y = spielfeldgroesse - 1; y >= 2; y--) { //-1 für array, 2 weil reuhe nicht übers Spielfeld "
            if ((*spielfeld)[x][y] == P1 && (*spielfeld)[x + 1][y - 1] == P1 && (*spielfeld)[x + 2][y - 2] == P1)
                return P1;
            if ((*spielfeld)[x][y] == P2 && (*spielfeld)[x + 1][y - 1] == P2 && (*spielfeld)[x + 2][y - 2] == P2)
                return P2;
        }
    }
    return NoP;
}

bool unentschieden_checker(size_t spielfeldgroesse, enum feldkasten (*spielfeld)[spielfeldgroesse][spielfeldgroesse]) {
    bool ret = false;
    // Check: gibt es NoPs im Spielfeld
    for (int i = 0; i < spielfeldgroesse; i++) {
        for (int j = 0; j < spielfeldgroesse; j++)
            ret |= (*spielfeld)[i][j] == NoP;
    }
    return !ret; // kein NoP vorhanden → Spielfeld voll besetzt
}


int main() {
    printf("Spielfeldgroesse (mind. 3, maximal 10) ? ");
    int spielfeldgroesse = 0;
    scanf_sizet(&spielfeldgroesse);

    while (spielfeldgroesse < 3 || spielfeldgroesse > 10) {
        printf("Invalide Spielfeldgröße, versuche erneut ? ");
        scanf_sizet(&spielfeldgroesse);
    }

    enum feldkasten spielfeld[spielfeldgroesse][spielfeldgroesse];
    // initialisiere und leere Spielfeld
    for (int i = 0; i < spielfeldgroesse; i++) {
        for (int j = 0; j < spielfeldgroesse; j++)
            spielfeld[i][j] = NoP;
    }

    // das Spiel beginnt!
    enum feldkasten spieler_dran = P1;
    print_spielfeld(spielfeldgroesse, &spielfeld);

    while (true) {
        printf("Dein Zug, Spieler %d (x,y) ? ", spieler_dran == P1 ? 1 : 2);

    eingabe:
        int xpos = -1, ypos = -1;
        scanf_koordinate(&ypos, &xpos);
        while ((xpos < 0 || xpos > spielfeldgroesse) || (ypos < 0 || ypos > spielfeldgroesse)) {
            printf("invalide Eingabe. Probiere nochmal ? ");
            scanf_koordinate(&ypos, &xpos);
        }
        if (spielfeld[xpos][ypos] != NoP) { // spieler versuch gesetzten Wert zu überschreiben
            printf("unerlaubter Spielzug! Probiere nochmal ? ");
            goto eingabe;
        }

        spielfeld[xpos][ypos] = spieler_dran;
        print_spielfeld(spielfeldgroesse, &spielfeld);

        // ein Spieler hat gewonnen!
        if (gewinn_checker(spielfeldgroesse, &spielfeld) != NoP) {
            printf("Spieler %d hat gewonnen!", spieler_dran == P1 ? 1 : 2);
            break;
        }
        // das spielfeld ist voll und keiner hat gewonnen!
        if (unentschieden_checker(spielfeldgroesse, &spielfeld)) {
            printf("Keiner hat gewonnen :(");
            break;
        }

        spieler_dran == P1 ? (spieler_dran = P2) : (spieler_dran = P1);
    }
}
