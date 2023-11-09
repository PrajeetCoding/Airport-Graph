#include "Utility.h"
using namespace std;


/*
    Input: Two pairs of longitude/latitude values in radians
    Output: Their great circle distance in kilometers
*/
double Utility::distance(pair<double, double> first, pair<double, double> second) {
    double first_lat = DegreeToRadians(first.first);
    double first_long = DegreeToRadians(first.second);
    double second_lat = DegreeToRadians(second.first);
    double second_long = DegreeToRadians(second.second);
    return acos(sin(first_lat)*sin(second_lat)+cos(first_lat)*cos(second_lat)*cos(first_long-second_long)) * 6366.71;
}
/*
    Input: Degree value 
    Output: Corresponding radian value
*/
double Utility::DegreeToRadians(double degree) {
    return degree * (M_PI/180);
}