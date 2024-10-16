#include <iostream>
#include "MathUtils.h"
#include "ExplicitUpwindFiniteDifferenceSolver.h"

using namespace std;

int main()
{
    double xMin, xMax, tMax;
    int gridPoints;
    cout << "Enter the value for xMin, xMax, tMax and number of grid points: " << endl;
    cin >> xMin >> xMax >> tMax >> gridPoints;

    FiniteDifferenceSolver* stepSolver = new ExplicitUpwindFiniteDifferenceSolver(xMin, xMax, tMax, gridPoints, Function::STEP);
    FiniteDifferenceSolver* gaussianSolver = new ExplicitUpwindFiniteDifferenceSolver(xMin, xMax, tMax, gridPoints, Function::GAUSSIAN);

    // This function calculates and prints the exact and numerical solution along with errors.
    stepSolver->printSolution();
    gaussianSolver->printSolution();

    delete stepSolver;
    delete gaussianSolver;
    return 0;
}