//
// Created by LUIBROS on 21.12.2022.
//

#include "functions.h"
#include "math.h"

double f(double xn) {
    return pow(xn - 3, 2);
}

double fAnalyticalApproximation(double xn) {
    return 2 * (xn - 3);
}

double fNumericalApproximation(double xn) {
    double h = pow(10, -8);
    return ( f(xn + h) - f(xn) ) / h;
}

