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

double *rightHandSide(double speed, double position) {
    double m = 1.0; // mass of object
    double c = 5.0; // feder constant
    double d = 0.25; // damper constant

    double *returnValue = malloc(sizeof(double) * 2);

    returnValue[0] = speed; // speed
    returnValue[1] = -((d * speed / m) + (c * position / m)); // acceleration
    return returnValue;
}

void eulerForward() {
    /*get user defined Simtime*/
    printf("Simtime (in s): \n");
    double time_0 = scanForNumericInput();

    /*get user defined StepSize*/
    printf("StepSize (in s): \n");
    double stepSize = scanForNumericInput();

    /*get init state position*/
    printf("position(t = 0): \n");
    double  position_0 = scanForNumericInput();

    /*get init state speed*/
    printf("speed(t = 0): \n");
    double speed_0 = scanForNumericInput();

//    double position_0 = 1;
//    double speed_0 = 0;
//    double time_0 = 50;
//    double stepSize = 0.01;
    double iterations = ceil(time_0 / stepSize);;

    double position = position_0;
    double speed = speed_0;
    double time = 0;

    remove("data.txt");

    FILE *fPtr = fopen("data.txt", "a");
    if(fPtr == NULL) {
        printf("Could not open file");
        return;
    }

    for (int i = 0; i < iterations; i++) {
        double *rhd = rightHandSide(speed, position);

        // neuer speed = alter speed + (stepSize * neue acceleration)
        speed = speed + (stepSize * rhd[1]);
        // neue pos = alte pos + (stepSize * neuer Speed)
        position = position + (stepSize * rhd[0]);
        time = time + stepSize;

        fprintf(fPtr, "%lf %lf %lf\n", time, position, speed);
        printf("v: %lf; x: %lf; t: %lf\n", speed, position, time);
    }

    fclose(fPtr);

    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

    fprintf(gnuplotPipe, "set xlabel 'time in sec'\n"
                         "plot 'data.txt' using 1:2 title 'position',"
                              "'data.txt' using 1:3 title 'speed'\n");
    fprintf(gnuplotPipe, "exit");

    fclose(gnuplotPipe);
}