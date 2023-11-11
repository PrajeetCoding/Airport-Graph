#pragma once

#define _USE_MATH_DEFINES

#include <utility>
#include <cmath>

namespace Utility {
    //Calculates the great circle distance between two points given in latitude and longitude with RADIANS as units
    double distance(std::pair<double, double> first, std::pair<double, double> second);

    //Convert degree double to radian double
    double DegreeToRadians(double dec);
}