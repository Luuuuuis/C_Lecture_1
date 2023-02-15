#include <stdlib.h>
#include "eulerLib.h"

int main() {
    SimulationProperties *simProps = promptUserInput();
    simProps->function = rightHandSide;

    eulerForward(simProps);
    showResults();

    free(simProps);
}