#include <stdio.h>
#include <stdlib.h>
#include "eulerLib.h"

double scanForNumericInput() {
    double value;

    while (scanf("%lf", &value) != 1) {
        printf("Invalid input... Please input an integer.\nTry again: \n");
        fflush(stdin); // flush any leftover characters in the stdin
    }

    return value;
}

SimulationProperties *promptUserInput() {
    SimulationProperties *simProps = malloc(sizeof(SimulationProperties));

    printf("Simulation time (in s): \n");
    simProps->time = scanForNumericInput();

    printf("StepSize: \n");
    simProps->stepSize = scanForNumericInput();

    printf("Start position: \n");
    simProps->position = scanForNumericInput();

    printf("Start speed: \n");
    simProps->speed = scanForNumericInput();

    return simProps;
}

int main() {
    SimulationProperties *simProps = promptUserInput();
    simProps->f = rightHandSide;

    eulerForward(simProps);

}