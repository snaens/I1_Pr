/* Erstellen Sie ein C-Programm teilbar.c, das zwei ganze Zahlen x und y einliest und dann ausgibt, ob x durch y teilbar ist.
 * Mögliche Abläufe dieses Programms teilbar.c:
 *    Zahl x durch Zahl y teilbar ?
 *    =============================
 *    Dieses Programm sagt Ihnen, ob eine Zahl x durch eine Zahl y
 *    teilbar ist. Dazu muessen nur die beiden ganzen Zahlen x und y eingeben.
 *    x? 1000 ↩
 *    y? 8 ↩
 *        1000 ist durch 8 .....teilbar
 *
 *    Zahl x durch Zahl y teilbar ?
 *    =============================
 *    Dieses Programm sagt Ihnen, ob eine Zahl x durch eine Zahl y
 *    teilbar ist. Dazu muessen nur die beiden ganzen Zahlen x und y eingeben.
 *    x? 721 ↩
 *    y? 3 ↩
 *        721 ist durch 3 .....nicht teilbar
 */

#include<stdio.h>

int main() {
    printf("Zahl x durch Zahl y teilbar ?\n"
           "=============================\n"
           "Dieses Programm sagt Ihnen, ob eine Zahl x durch eine Zahl y\n"
           "teilbar ist. Dazu muessen nur die beiden ganzen Zahlen x und y eingeben.\n");

    // x eingabe
    printf("x? ");
    int x;
    scanf("%d", &x);

    // y eingabe
    printf("y? ");
    int y;
    scanf("%d", &y);

    printf("    %d ist durch %i .....%steilbar\n", x, y, (x%y == 0 ? "" : "nicht "));
    // printf("    %d ist durch %i ....."));
    // if (!x%y==0) printf("nicht ")
    // printf("teilbar\n")
}
