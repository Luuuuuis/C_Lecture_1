//
// Created by LUIBROS on 15.12.2022.
//

#include "calculator.h"
#include "complex_number.h"

Complex_Number add(Complex_Number number1, Complex_Number number2) {
    Complex_Number result;

    result.real = number1.real + number2.real;
    result.imaginary = number1.imaginary + number2.imaginary;

    return result;
}

Complex_Number subtract(Complex_Number number1, Complex_Number number2) {
    Complex_Number result;

    result.real = number1.real - number2.real;
    result.imaginary = number1.imaginary - number2.imaginary;

    return result;
}

Complex_Number multiply(Complex_Number number1, Complex_Number number2) {
    Complex_Number result;

    result.real = number1.real * number2.real - number1.imaginary * number2.imaginary;
    result.imaginary = number1.real * number2.imaginary + number2.real * number1.imaginary;

    return result;
}

Complex_Number divide(Complex_Number number1, Complex_Number number2) {
    double a = number1.real;
    double b = number1.imaginary;
    double c = number2.real;
    double d = number2.imaginary;

    Complex_Number result;

    result.real = (a*c + b*d)/(c*c + d*d);
    result.imaginary = (b*c - a*d)/(c*c + d*d);

    return result;
}