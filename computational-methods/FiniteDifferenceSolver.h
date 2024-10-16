#pragma once

#include <vector>

using namespace std;

enum class Function
{
    STEP,
    GAUSSIAN,
};

class FiniteDifferenceSolver
{
public:
    FiniteDifferenceSolver(double xMin, double xMax, double tMax, int gridPoints, Function function);
    vector<double> getGridPoints();
    vector<double> computeExactSolution();
    vector<double> computeInitialCondition();
    void printSolution();
    virtual vector<double> computeNumericalSolution() = 0;

protected:
    double xMin, xMax, tMax, dx, dt;
    int gridPoints;
    vector<double> points;
    Function function;

};