//
// Created by LUIBROS on 15.12.2022.
//

#include <stdio.h>
#include "./libs/complex_number.h"
#include "./libs/calculator.h"

int main() {

    Complex_Number number1, number2;

    printf("gib die erste komplexe zahl ein ein: ");
    scanf("%lf+%lfi", &number1.real, &number1.imaginary);

    printf("gib die zweite komplexe zahl ein ein: ");
    scanf("%lf+%lfi", &number2.real, &number2.imaginary);

    Complex_Number result = add(number1, number2);
    printf("Das der addition ist \"%lf+%lfi\"\n", result.real, result.imaginary);

    Complex_Number result1 = subtract(number1, number2);
    printf("Das der subtraktion ist \"%lf+%lfi\"\n", result1.real, result1.imaginary);

    Complex_Number result2 = multiply(number1, number2);
    printf("Das der multiplikation ist \"%lf+%lfi\"\n", result2.real, result2.imaginary);

    Complex_Number result3 = divide(number1, number2);
    printf("Das der division ist \"%lf+%lfi\"\n", result3.real, result3.imaginary);

    return 0;
}