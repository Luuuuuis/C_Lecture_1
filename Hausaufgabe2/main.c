//
// Created by LUIBROS on 21.12.2022.
//

#include <stdio.h>
#include "math.h"
#include "./libs/newton.h"
#include "./libs/functions.h"

int main() {
    double x;
    int approximation;

    printf("Gib den Startwert x0 ein: ");
    scanf("%lf", &x);

    printf("Soll die numerische Approximation [1] oder die analytische Ableitung [2] verwendet werden? ");
    scanf("%d", &approximation);

    int i = 0;
    for (; i < 1000; i++) { // Abbruchbedingeing max. 1000 Iterationen
        double xMinus1 = x;

        x = iteration(x, &f, (approximation == 1 ? &fNumericalApproximation : &fAnalyticalApproximation));
        printf("%1.10f\n", x);

        // Abbruchbedingung
        if(x - xMinus1 < pow(10, -10)) {
            printf("Abbruchbedingung: delta x kleiner als %1.10f\n", pow(10, -10));
            break;
        }
    }

    printf("Es wurden %d Iterationen gebraucht um auf %1.10f zu kommen\n", i, x);
    printf("Die Nullstelle befindet sich in etwa bei %1.10f", x);

    return 0;
}
