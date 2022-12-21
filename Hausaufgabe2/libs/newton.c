//
// Created by LUIBROS on 21.12.2022.
//

#include "newton.h"

double iteration(double xn, double (*f_ptr)(double), double (*fDerivation_ptr)(double)) {
    return xn - (*f_ptr)(xn) / (*fDerivation_ptr)(xn);
}

