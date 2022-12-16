//
// Created by LUIBROS on 15.12.2022.
//

#include <stdio.h>
#include "./libs/calculator.h"
#include "./libs/complex_number.h"

int main() {

    Complex_Number_Cartesian number1, number2;

    printf("Gib die erste Zahl in karthesischer Form ein: ");
    scanf("%lf+%lfi", &number1.real, &number1.imaginary);

    printf("Gib die zweite Zahl in karthesischer Form ein: ");
    scanf("%lf+%lfi", &number2.real, &number2.imaginary);

    int form = 1;

    printf("Wie soll es Ausgegeben werden? \n"
           "[1] karthesisch: z=a+bi\n"
           "[2] polar1: z=r*e^(iΦ)\n"
           "[3] polar2: z=r*(cos(Φ) + i sin(Φ))\n");
    scanf("%d", &form);


    Complex_Number_Cartesian result = add(number1, number2);
    Complex_Number_Cartesian result1 = subtract(number1, number2);
    Complex_Number_Cartesian result2 = multiply(number1, number2);
    Complex_Number_Cartesian result3 = divide(number1, number2);

    Complex_Number_Polar polarResult = cartesianToPolar(result);
    Complex_Number_Polar polarResult1 = cartesianToPolar(result1);
    Complex_Number_Polar polarResult2 = cartesianToPolar(result2);
    Complex_Number_Polar polarResult3 = cartesianToPolar(result3);

    switch (form) {
        default:
        case 1:
            printf("Das Ergebnis der Addition ist \"z=%lf+%lfi\"\n", result.real, result.imaginary);
            printf("Das Ergebnis der Subtraktion ist \"z=%lf+%lfi\"\n", result1.real, result1.imaginary);
            printf("Das Ergebnis der Multiplikation ist \"z=%lf+%lfi\"\n", result2.real, result2.imaginary);
            printf("Das Ergebnis der Division ist \"z=%lf+%lfi\"\n", result3.real, result3.imaginary);
            break;
        case 2:
            printf("Das Ergebnis der Addition ist \"z=%lf*e^(i%lf)\"\n", polarResult.absolut, polarResult.angle);
            printf("Das Ergebnis der Subtraktion ist \"z=%lf*e^(i%lf)\"\n", polarResult1.absolut, polarResult1.angle);
            printf("Das Ergebnis der Multiplikation ist \"z=%lf*e^(i%lf)\"\n", polarResult2.absolut, polarResult2.angle);
            printf("Das Ergebnis der Division ist \"z=%lf*e^(i%lf)\"\n", polarResult3.absolut, polarResult3.angle);
            break;
        case 3:
            printf("Das Ergebnis der Addition ist \"z=%lf*(cos(%lf)+i*sin(%lf))\"\n", polarResult.absolut, polarResult.angle, polarResult.angle);
            printf("Das Ergebnis der Subtraktion ist \"z=%lf*(cos(%lf)+i*sin(%lf))\"\n", polarResult1.absolut, polarResult1.angle, polarResult1.angle);
            printf("Das Ergebnis der Multiplikation ist \"z=%lf*(cos(%lf)+i*sin(%lf))\"\n", polarResult2.absolut, polarResult2.angle, polarResult2.angle);
            printf("Das Ergebnis der Division ist \"z=%lf*(cos(%lf)+i*sin(%lf))\"\n", polarResult3.absolut, polarResult3.angle, polarResult3.angle);
            break;
    }

    return 0;
}