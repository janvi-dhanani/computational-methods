#pragma once

#include "FiniteDifferenceSolver.h"

class ExplicitUpwindFiniteDifferenceSolver : public FiniteDifferenceSolver
{
public:
	ExplicitUpwindFiniteDifferenceSolver(double xMin, double xMax, double tMax, int gridPoints, Function function);
	vector<double> computeNumericalSolution();
};