#include <stdlib.h>
#include "eulerLib.h"

int main() {
    SimulationProperties *simProps = promptUserInput();
    simProps->f = rightHandSide;

    eulerForward(simProps);
    showResults();

    free(simProps);
}