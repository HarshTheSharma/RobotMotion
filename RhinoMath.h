#ifndef RHINOMATH_H
#define RHINOMATH_H
#include "MasterHeader.h"

class RhinoMath
{
private:
	double ArmA;
	double ArmB;
	double CompAng2(double, double);          //make private add point pair
	double CompAng1(double, double, double);  //make private
public:
	RhinoMath(double = 9.0, double = 9.0);
    AnglePair getAngpair(PointXY xy);     //make public
};
#endif

