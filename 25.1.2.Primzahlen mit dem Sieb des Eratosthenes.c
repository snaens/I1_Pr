/* Es sollen alle Primzahlen zwischen 1 und 1000 bestimmt werden. Sazu soll das sogenannte Sieb
 * des Eratosthenes verwendet werden, das folgende Vorgehensweise vorschreibt: Zunächst wird
 * auf die Zahl 2 positioniert, und dann alle Vielfachen von 2 herausgestrichen, was nachfolgend
 * durch Unterstreichen der betreffenden Zahlen gezeigt ist:
 *   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 ...
 *     ↑   -   -   -   --    --    --    --    --
 * Im nächsten Schritt wird um eine Zahl weiterpositioniert, in unserem Fall also auf 3; ist diese
 * Zahl noch vorhanden, so handelt es sich um eine Primzahl, von der wiederum alle Vielfachen
 * zu streichen sind:
 *   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 ...
 *       ↑ -   -   - - --    --    -- -- --   --
 * Die nächste Primzahl nach 3 wäre dann 5 (noch nicht gestrichen), von der wieder alle Vielfachen
 * zu streichen sind usw. Dieses Verfahren wird wiederholt, bis 1000 erreicht ist.
 * Ablauf des Programms primsieb.c:
 *     Die Primzahlen von 1 bis 1000 sind:
 *     2    3    5    7    11   13   17   19   23   29
 *     31   37   41   43   47   53   59   61   67   71
 *     73   79   83   89   97   101  103  107  109  113
 *     127  131  137  139  149  151  157  163  167  173
 *     179  181  191  193  197  199  211  223  227  229
 *     233  239  241  251  257  263  269  271  277  281
 *     283  293  307  311  313  317  331  337  347  349
 *     353  359  367  373  379  383  389  397  401  409
 *     419  421  431  433  439  443  449  457  461  463
 *     467  479  487  491  499  503  509  521  523  541
 *     547  557  563  569  571  577  587  593  599  601
 *     607  613  617  619  631  641  643  647  653  659
 *     661  673  677  683  691  701  709  719  727  733
 *     739  743  751  757  761  769  773  787  797  809
 *     811  821  823  827  829  839  853  857  859  863
 *     877  881  883  887  907  911  919  929  937  941
 *     947  953  967  971  977  983  991  997
 */

#include <stdio.h>

#define MAX_WERT 1000


int main() {
    bool sind_primzahlen[MAX_WERT + 1]; // zur vereinfachung indexen wir das Array beginnend mit 1, index 0 ist halt ne bonus 0

    for (int i = 0; i <= MAX_WERT; i++) {
        sind_primzahlen[i] = true;
    } // array mit true füllen
    sind_primzahlen[1] = false; // 1 ist keine Primzahl, wir fangen bei 2 an

    printf("Die Primzahlen von 1 bis %d sind:\n", MAX_WERT);

    for (int primzahl = 2; primzahl <= MAX_WERT;) { // fangen bei 2 an
        for (int multiplier = primzahl; primzahl * multiplier <= MAX_WERT; multiplier++) {
            // Primzahlen sind nur mit 1 und sich selbst teilbar => wir vermeiden diese beiden Fälle
            sind_primzahlen[primzahl * multiplier] = false;
        }
        do {
            primzahl++;
        } while (sind_primzahlen[primzahl] == false && primzahl <= MAX_WERT);
    }

    // Array ausgeben
    for (int i = 1; i <= MAX_WERT; i++) {
        if (sind_primzahlen[i]) {
            static int c = 1;
            printf("%8d", i);
            if (c % 10 == 0)
                printf("\n"); // wrap jede 10 Zahlen
            c++;
        }
    }
    printf("\n");
}
