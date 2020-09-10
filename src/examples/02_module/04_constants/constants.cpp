/*
Function get_area_of_circle given the radius returns the area of a circle.
Create const double PI with 3.14159

@param double radius-radius of circle
@return the area of a circle
*/
#include "constants.h"
const double PI = 3.14159;
double get_area_of_circle(double radius)
{
    return PI*radius*radius;
}