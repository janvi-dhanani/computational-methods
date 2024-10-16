#pragma once

#include <vector>
#include <cmath>
#include <iostream>

//  constant macros
#define U 1.75  
#define CFL 0.9

using namespace std;

inline vector<double> computeErrors(vector<double> exactSolution, vector<double> numericalSolution)
{
    vector<double> errors(exactSolution.size());
    for (int i = 0; i < exactSolution.size(); i++)
    {
        errors[i] = fabs(numericalSolution[i] - exactSolution[i]);
    }
    return errors;
}

inline int signum(double x)
{
    return x > 0 ? 1 : (x < 0 ? -1 : 0);
}

inline void print(vector<double> x)
{
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << endl;
    }
}