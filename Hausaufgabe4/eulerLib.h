//
// Created by LUIBROS on 10.02.2023.
//

#ifndef EULERLIB_H
#define EULERLIB_H

typedef struct {
    double *(*f)(double, double);
    double time;
    double stepSize;
    double position;
    double speed;
} SimulationProperties;

double *rightHandSide(double speed, double position);
void eulerForward(SimulationProperties *simProp);

#endif //EULERLIB_H
