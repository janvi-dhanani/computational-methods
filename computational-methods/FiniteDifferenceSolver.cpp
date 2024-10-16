

#include "FiniteDifferenceSolver.h"
#include "MathUtils.h"

using namespace std;

FiniteDifferenceSolver::FiniteDifferenceSolver(double xMin, double xMax, double tMax, int gridPoints, Function function) : xMin(xMin), xMax(xMax), tMax(tMax), gridPoints(gridPoints), function(function)
{
    dx = (xMax - xMin) / gridPoints;
    dt = CFL * dx / U;

    for (double i = xMin; i <= xMax; i += dx)
    {
        points.push_back(i);
    }
}

vector<double> FiniteDifferenceSolver::getGridPoints()
{
    return points;
}

vector<double> FiniteDifferenceSolver::computeExactSolution()
{
    vector<double> exactSolution(points.size(), 0);

    switch (function)
    {
    case Function::STEP:
        for (int i = 0; i < points.size(); i++)
        {
            exactSolution[i] = 0.5 * signum(points[i] - U * tMax + 1);
        }
        break;

    case Function::GAUSSIAN:
        for (int i = 0; i < points.size(); i++)
        {
            exactSolution[i] = 0.5 * exp(-pow((points[i] - U * tMax), 2));
        }
        break;
    }

    return exactSolution;
}

vector<double> FiniteDifferenceSolver::computeInitialCondition()
{
    vector<double> initialCondition(points.size(), 0);

    switch (function)
    {
    case Function::STEP:
        for (int i = 0; i < points.size(); i++)
        {
            initialCondition[i] = 0.5 * signum(points[i] + 1);
        }
        break;

    case Function::GAUSSIAN:
        for (int i = 0; i < points.size(); i++)
        {
            initialCondition[i] = 0.5 * exp(-pow(points[i], 2));
        }
        break;
    }
    return initialCondition;
}

void FiniteDifferenceSolver::printSolution()
{
    vector<double> exactSolution = computeExactSolution();
    vector<double> numericalSolution = computeNumericalSolution();
    vector<double> errors = computeErrors(exactSolution, numericalSolution);
    cout << "X \t\t Exact Solution \t\t Numerical Solution \t\t Error" << endl;
    for (int i = 0; i < points.size(); i++)
    {
        cout << points[i] << "\t\t" << exactSolution[i] << "\t\t" << numericalSolution[i] << "\t\t" << errors[i] << endl;
    }
}
