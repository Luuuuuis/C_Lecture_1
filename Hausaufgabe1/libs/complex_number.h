//
// Created by LUIBROS on 15.12.2022.
//

#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H


typedef struct {
    double real;
    double imaginary;
} Complex_Number_Cartesian;

typedef struct { //https://en.wikipedia.org/wiki/Complex_number#Notation
    double absolut;
    double angle;
} Complex_Number_Polar;

#endif
