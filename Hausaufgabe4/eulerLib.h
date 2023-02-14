//
// Created by LUIBROS on 10.02.2023.
//

#ifndef EULERLIB_H
#define EULERLIB_H

typedef struct {
    double time;
    double position;
    double speed;
} Vector;

typedef struct {
    double *(*function)(double, double);
    double stepSize;
    double duration;
    int iterations;

    Vector *vectors;
} SimulationProperties;

SimulationProperties *promptUserInput();

double *rightHandSide(double speed, double position);

void eulerForward(SimulationProperties *simProp);

void showResults();

#endif //EULERLIB_H
