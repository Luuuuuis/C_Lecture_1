//
// Created by LUIBROS on 10.02.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

    printf("Simulation duration (in s): \n");
    simProps->duration = scanForNumericInput();

    printf("StepSize: \n");
    simProps->stepSize = scanForNumericInput();

    simProps->iterations = ceil(simProps->duration / simProps->stepSize);
    Vector *vectors = malloc((simProps->iterations + 1) * sizeof(Vector));
    simProps->vectors = vectors;

    Vector vector_0;
    vector_0.time = 0;

    printf("Start position: \n");
    vector_0.position = scanForNumericInput();

    printf("Start speed: \n");
    vector_0.speed = scanForNumericInput();

    simProps->vectors[0] = vector_0;

    return simProps;
}

double *rightHandSide(double speed, double position) {

    // "Normaler" Fall
//    double m = 1.0; // mass of object
//    double c = 5.0; // feder constant
//    double d = 0.25; // damper constant

    // Aperiodischer-Grenzfall
    double m = 1.0;
    double c = 2.0;
    double d = 3;

    double *returnValue = malloc(sizeof(double) * 2);

    returnValue[0] = speed; // speed
    returnValue[1] = -((d * speed / m) + (c * position / m)); // acceleration
    return returnValue;
}

void eulerForward(SimulationProperties *simProp) {
    FILE *fPtr = fopen("data.txt", "w");
    if (fPtr == NULL) {
        printf("Could not open file");
        return;
    }

    for (int i = 0; i < simProp->iterations; i++) {
        double *rhd = simProp->function(simProp->vectors[i].speed, simProp->vectors[i].position);

        // neuer speed = alter speed + (stepSize * neue acceleration)
        simProp->vectors[i + 1].speed = simProp->vectors[i].speed + (simProp->stepSize * rhd[1]);

        // neue pos = alte pos + (stepSize * neuer Speed)
        simProp->vectors[i + 1].position = simProp->vectors[i].position + (simProp->stepSize * rhd[0]);

        // neue time = alte time + stepSize
        simProp->vectors[i + 1].time = simProp->vectors[i].time + simProp->stepSize;

        fprintf(fPtr, "%lf %lf %lf\n", simProp->vectors[i].time, simProp->vectors[i].position, simProp->vectors[i].speed);
        //printf("t: %lf; v: %lf; x: %lf\n", simProp->vectors[i].time, simProp->vectors[i].speed, simProp->vectors[i].position);

        free(rhd);
    }

    fclose(fPtr);
}

void showResults() {
    FILE *gnuplotPipe = popen("gnuplot --persist", "w");

    fprintf(gnuplotPipe, "set title 'Results'\n"
                         "set xlabel 'time in sec'\n"
                         "plot 'data.txt' using 1:2 title 'position',"
                         "'data.txt' using 1:3 title 'speed'\n");
    fprintf(gnuplotPipe, "exit");

    fclose(gnuplotPipe);
}