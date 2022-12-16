//
// Created by LUIBROS on 15.12.2022.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "complex_number.h"

Complex_Number_Cartesian add(Complex_Number_Cartesian number1, Complex_Number_Cartesian number2);
Complex_Number_Cartesian subtract(Complex_Number_Cartesian number1, Complex_Number_Cartesian number2);
Complex_Number_Cartesian multiply(Complex_Number_Cartesian number1, Complex_Number_Cartesian number2);
Complex_Number_Cartesian divide(Complex_Number_Cartesian number1, Complex_Number_Cartesian number2);
Complex_Number_Polar cartesianToPolar(Complex_Number_Cartesian numberCartesian);

#endif
