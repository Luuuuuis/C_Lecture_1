//
// Created by LUIBROS on 15.12.2022.
//

#include <math.h>
#include "calculator.h"
#include "complex_number.h"

Complex_Number_Cartesian add(Complex_Number_Cartesian number1, Complex_Number_Cartesian number2) {
    Complex_Number_Cartesian result;

    result.real = number1.real + number2.real;
    result.imaginary = number1.imaginary + number2.imaginary;

    return result;
}

Complex_Number_Cartesian subtract(Complex_Number_Cartesian number1, Complex_Number_Cartesian number2) {
    Complex_Number_Cartesian result;

    result.real = number1.real - number2.real;
    result.imaginary = number1.imaginary - number2.imaginary;

    return result;
}

Complex_Number_Cartesian multiply(Complex_Number_Cartesian number1, Complex_Number_Cartesian number2) {
    Complex_Number_Cartesian result;

    result.real = number1.real * number2.real - number1.imaginary * number2.imaginary;
    result.imaginary = number1.real * number2.imaginary + number2.real * number1.imaginary;

    return result;
}

Complex_Number_Cartesian divide(Complex_Number_Cartesian number1, Complex_Number_Cartesian number2) {
    double a = number1.real;
    double b = number1.imaginary;
    double c = number2.real;
    double d = number2.imaginary;

    Complex_Number_Cartesian result;

    result.real = (a*c + b*d)/(c*c + d*d);
    result.imaginary = (b*c - a*d)/(c*c + d*d);

    return result;
}

Complex_Number_Polar cartesianToPolar(Complex_Number_Cartesian numberCartesian) {
    Complex_Number_Polar result;

    result.absolut = sqrt(pow(numberCartesian.real, 2) + pow(numberCartesian.imaginary, 2));
    result.angle = atan(numberCartesian.imaginary / numberCartesian.real);

    return result;
}