#include "ExplicitUpwindFiniteDifferenceSolver.h"
#include "MathUtils.h"

ExplicitUpwindFiniteDifferenceSolver::ExplicitUpwindFiniteDifferenceSolver(double xMin, double xMax, double tMax, int gridPoints, Function function) : FiniteDifferenceSolver(xMin, xMax, tMax, gridPoints, function)
{}

vector<double> ExplicitUpwindFiniteDifferenceSolver::computeNumericalSolution()
{
    vector<double> numericalSolution = computeInitialCondition();
    for (double t = 0; t <= tMax; t += dt)
    {
        numericalSolution[0] = 0;
        for (int i = 1; i < points.size(); i++)
        {
            numericalSolution[i] = -CFL * numericalSolution[i - 1] + (1 + CFL) * numericalSolution[i];
        }
        switch (function)
        {
        case Function::STEP:
            numericalSolution[points.size() -1] = 1;
            break;
        case Function::GAUSSIAN:
            numericalSolution[points.size()-1] = 0;
            break;
        default:
            break;
        }
    }
    return numericalSolution;
}
