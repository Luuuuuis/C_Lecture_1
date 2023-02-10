//
// Created by LUIBROS on 10.02.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eulerLib.h"

double *rightHandSide(double speed, double position) {
/*    double m = 1.0; // mass of object
    double c = 5.0; // feder constant
    double d = 0.25; // damper constant*/
    double m = 1.0;
    double c = 2.0;
    double d = 3;

    double *returnValue = malloc(sizeof(double) * 2);

    returnValue[0] = speed; // speed
    returnValue[1] = -((d * speed / m) + (c * position / m)); // acceleration
    return returnValue;
}

void eulerForward(SimulationProperties *simProp) {
    double iterations = ceil(simProp->time / simProp->stepSize);;

    double position = simProp->position;
    double speed = simProp->speed;
    double time = 0;

    remove("data.txt");

    FILE *fPtr = fopen("data.txt", "a");
    if (fPtr == NULL) {
        printf("Could not open file");
        return;
    }

    for (int i = 0; i < iterations; i++) {
        double *rhd = rightHandSide(speed, position);

        // neuer speed = alter speed + (stepSize * neue acceleration)
        speed = speed + (simProp->stepSize * rhd[1]);
        // neue pos = alte pos + (stepSize * neuer Speed)
        position = position + (simProp->stepSize * rhd[0]);
        time = time + simProp->stepSize;

        fprintf(fPtr, "%lf %lf %lf\n", time, position, speed);
        printf("t: %lf; v: %lf; x: %lf\n", time, speed, position);
    }

    fclose(fPtr);

    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

    fprintf(gnuplotPipe, "set title 'Results'\n"
                         "set xlabel 'time in sec'\n"
                         "plot 'data.txt' using 1:2 title 'position',"
                         "'data.txt' using 1:3 title 'speed'\n");
    fprintf(gnuplotPipe, "exit");

    fclose(gnuplotPipe);
}